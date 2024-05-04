#include "VertDesktop.h"
#include "VertResources.h"


void vert_awake() {
    VertSettings::get()->init();
    // Hi
}


void vert_start() {
    ImGui::StyleColorsDark();

    auto style = VertStyle::get();

    style->setup();
    style->updateColors();

    VertResources::get()->init();

    VertStyle::get()->setupWindowIcon();

    if (GET_SETTING(maximize))
        glfwMaximizeWindow(VertShared::Window);
}


void vert_main_update() {

    VertKeys::get()->update();
    VertMainMenu::get()->render();
    VertFpsCounter::get()->render();
    VertAbout::get()->render();

    VertWidgets::VertRegisterForm();


    if (GET_SETTING(show_demo)) {
        ImGui::ShowDemoWindow(&GET_SETTING(show_demo));
    }

}


void vert_on_exit() {
    auto maximized = glfwGetWindowAttrib(VertShared::Window, GLFW_MAXIMIZED) == GLFW_TRUE;
    SET_SETTING(maximize, maximized);

    int window_x_pos, window_y_pos;
    int window_x_size, window_y_size;

    glfwGetWindowPos(VertShared::Window, &window_x_pos, &window_y_pos);
    glfwGetWindowSize(VertShared::Window, &window_x_size, &window_y_size);

    if (!maximized) {
        SET_SETTING(window_pos_x, window_x_pos);
        SET_SETTING(window_pos_y, window_y_pos);

        SET_SETTING(window_size_x, window_x_size);
        SET_SETTING(window_size_y, window_y_size);
    }

    VertSettings::get()->save();
}


int vert_main() { // ДАЛЬШЕ БОГА НЕТ
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        return 1;

    vert_awake();

    auto glsl_version = VertShared::getGlslVersion();

    VertShared::Window = glfwCreateWindow(GET_SETTING(window_size_x), GET_SETTING(window_size_y), "Vert", nullptr, nullptr);
    if (VertShared::Window == nullptr)
        return 1;

    glfwMakeContextCurrent(VertShared::Window);

    glfwSetWindowPos(VertShared::Window, GET_SETTING(window_pos_x), GET_SETTING(window_pos_y));

    IMGUI_CHECKVERSION();

    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
    io.IniFilename = nullptr;

    ImGui_ImplGlfw_InitForOpenGL(VertShared::Window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    vert_start();

    ImVec4 clear_color = ImVec4(0.1f, 0.1f, 0.1f, 0.99f);

    while (!glfwWindowShouldClose(VertShared::Window))
    {
        glfwSwapInterval(GET_SETTING(vsync) ? 1 : 0); // Just fuck you OpenGL
        glfwPollEvents();
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();

        ImGui::NewFrame();
        vert_main_update();
        ImGui::Render();


        int display_w, display_h;

        glfwGetFramebufferSize(VertShared::Window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(VertShared::Window);
    }

    vert_on_exit();
    vert_cleanup();

    return 0;
}


void vert_cleanup() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(VertShared::Window);
    glfwTerminate();
}


static void glfw_error_callback(int error, const char* description)
{
    spdlog::error("GLFW Error {}: {}", error, description);
}


#ifdef HIDE_WINDOWS_CONSOLE
    #include <Windows.h>
    #include <stdio.h>

    int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
        return vert_main();
    }

#else

    int main(int, char**)
    {
        return vert_main();
    }

#endif