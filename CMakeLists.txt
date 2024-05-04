cmake_minimum_required (VERSION 3.29)

project ("VertDesktop")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (WIN32)
	set(VCPKG_LIBRARY_LINKAGE static)
	set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Release>:Release>")

	set(HIDE_WINDOWS_CONSOLE_ False)
endif()

find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

file(GLOB_RECURSE PROJ_SRC src/*.cpp)
file(GLOB_RECURSE PROJ_SRC_H include/*.h*)

set(PROJ_EXEC_ADDITIONS "src/VertDesktop.cpp" ${PROJ_SRC} ${PROJ_SRC_H} ${IMGUI_SRC})

if (WIN32) 
	if (HIDE_WINDOWS_CONSOLE_)
		set(WIN32_ENTRY WIN32)
		add_compile_definitions(HIDE_WINDOWS_CONSOLE)
	endif()
	add_executable (${PROJECT_NAME} ${WIN32_ENTRY} ${PROJ_EXEC_ADDITIONS} resources.rc)
else()
	add_executable (${PROJECT_NAME} ${PROJ_EXEC_ADDITIONS})
endif()


target_include_directories(${PROJECT_NAME} PUBLIC 
	include
	include/widgets
)

set(LINKABLE_LIBS OpenGL::GL glfw imgui::imgui spdlog::spdlog nlohmann_json::nlohmann_json)

if (WIN32)
	target_link_directories(${PROJECT_NAME} PRIVATE thirdparty/windows)
	target_link_libraries(${PROJECT_NAME} PRIVATE glew32 ${LINKABLE_LIBS})
else()
	target_link_libraries(${PROJECT_NAME} PRIVATE ${LINKABLE_LIBS})
endif()

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                       ${CMAKE_SOURCE_DIR}/fonts/ ${PROJECT_BINARY_DIR}/fonts/)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                       ${CMAKE_SOURCE_DIR}/images/ ${PROJECT_BINARY_DIR}/images/)