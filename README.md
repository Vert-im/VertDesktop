# VertDesktop

![icon](https://github.com/Vert-im/VertDesktop/assets/61388196/1b4a7613-5e0f-4bf5-9451-c346b8da1ec5)

Instant messenger.

# Building on Windows

## Tools

- Microsoft Visual Studio >= 2019
- CMake 3.29
- C++20
- LLVM Clang(-cl) (TODO: test MSVC)
- vcpkg

## Preparation

Open Vert Desktop Folder Visual Studio

Go to Tools -> Options...

![image](https://github.com/Vert-im/VertDesktop/assets/61388196/6a6eea54-7c4e-4093-b386-7c9167345802)

Find CMake -> General, set custom CMake Executable Directory

![image](https://github.com/Vert-im/VertDesktop/assets/61388196/7575ae9c-00fc-40de-a278-7a4546e40118)

![image](https://github.com/Vert-im/VertDesktop/assets/61388196/3be7e499-a96b-4c47-be0b-5f19a8245fda)

Press OK

Install all dependencies using vcpkg:

`vcpkg install glfw3:x64-windows-static`

`vcpkg install imgui[core,opengl3-binding,glfw-binding]:x64-windows-static`

`vcpkg install spdlog:x64-windows-static`

`vcpkg install nlohmann-json:x64-windows-static`

**MAKE SURE YOU SET ALL PATHS IN CMakeSettings CORRECTLY! (for example, vcpkg toolchain path, dependencies paths etc.)**

## Building

Configure CMake with vcpkg toolchain file (I'm lazy to show you how, sorry) and press Build

Done!
