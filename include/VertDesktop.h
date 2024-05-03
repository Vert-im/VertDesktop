#pragma once
#include "VertShared.h"
#include "VertMainMenu.h"
#include "VertKeys.h"
#include "VertAbout.h"
#include "VertStyle.h"
#include "VertSettings.h"
#include "VertRegisterForm.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <spdlog/spdlog.h>
#include <stdio.h>
#define GL_SILENCE_DEPRECATION
#if defined(IMGUI_IMPL_OPENGL_ES2)
#include <GLES2/gl2.h>
#endif
#include <GLFW/glfw3.h>

#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif

static void glfw_error_callback(int error, const char* description);

void vert_awake();

void vert_start();

void vert_main_update();

void vert_on_exit();

void vert_cleanup();

int vert_main();