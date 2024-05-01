#include <VertStyle.h>
#include "stb_image.h"
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

VertStyle* VertStyle::get() {
    if (instance == nullptr) {
        instance = new VertStyle();
    }
    return instance;
}

void VertStyle::setup() {
    auto io = ImGui::GetIO();

    io.Fonts->AddFontFromFileTTF("consola.ttf", 16.0f, nullptr, io.Fonts->GetGlyphRangesCyrillic());
    VertShared::TitleFont = io.Fonts->AddFontFromFileTTF("consola.ttf", 32.0f, nullptr, io.Fonts->GetGlyphRangesCyrillic());

    updateColors();

    int v_w, v_h;

    loadTextureFromFile("icon.png", &VertShared::IconTexture, &v_w, &v_h);
    setupWindowIcon();

    ImGui::GetStyle().WindowRounding = 4;
    ImGui::GetStyle().FrameRounding = 3;
    ImGui::GetStyle().PopupRounding = 3;
    ImGui::GetStyle().WindowTitleAlign.x = .5f;
}

void VertStyle::updateColors() {
    ImVec4* colors = ImGui::GetStyle().Colors;

    colors[ImGuiCol_WindowBg] = ImVec4{ 0.12f, 0.12f, 0.12f, 1.0f };
    colors[ImGuiCol_FrameBg] = ImVec4(0.16f, 0.48f, 0.30f, 0.54f);

    colors[ImGuiCol_FrameBgHovered] = ImVec4(0.26f, 0.98f, 0.72f, 0.40f);
    colors[ImGuiCol_FrameBgActive] = ImVec4(0.26f, 0.98f, 0.70f, 0.67f);

    colors[ImGuiCol_TitleBgActive] = ImVec4(0.23f, 0.57f, 0.42f, 1.00f);

    colors[ImGuiCol_CheckMark] = ImVec4(0.26f, 0.98f, 0.46f, 1.00f);

    colors[ImGuiCol_SliderGrab] = ImVec4(0.24f, 0.88f, 0.69f, 1.00f);
    colors[ImGuiCol_SliderGrabActive] = ImVec4(0.26f, 0.98f, 0.74f, 1.00f);

    colors[ImGuiCol_Button] = ImVec4(0.26f, 0.98f, 0.44f, 0.40f);
    colors[ImGuiCol_ButtonHovered] = ImVec4(0.26f, 0.80f, 0.50f, 1.00f);
    colors[ImGuiCol_ButtonActive] = ImVec4(0.06f, 0.80f, 0.29f, 1.00f);

    colors[ImGuiCol_Header] = ImVec4(0.26f, 0.98f, 0.64f, 0.31f);
    colors[ImGuiCol_HeaderHovered] = ImVec4(0.26f, 0.98f, 0.77f, 0.80f);
    colors[ImGuiCol_HeaderActive] = ImVec4(0.26f, 0.98f, 0.64f, 1.00f);

    colors[ImGuiCol_SeparatorHovered] = ImVec4(0.10f, 0.75f, 0.57f, 0.78f);
    colors[ImGuiCol_SeparatorActive] = ImVec4(0.10f, 0.75f, 0.45f, 1.00f);

    colors[ImGuiCol_ResizeGrip] = ImVec4(0.26f, 0.98f, 0.62f, 0.20f);
    colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.26f, 0.98f, 0.36f, 0.67f);
    colors[ImGuiCol_ResizeGripActive] = ImVec4(0.26f, 0.98f, 0.38f, 0.95f);

    colors[ImGuiCol_Tab] = ImVec4(0.17f, 0.41f, 0.14f, 0.86f);
    colors[ImGuiCol_TabHovered] = ImVec4(0.26f, 0.98f, 0.70f, 0.80f);
    colors[ImGuiCol_TabActive] = ImVec4(0.20f, 0.68f, 0.55f, 1.00f);
    colors[ImGuiCol_TabUnfocused] = ImVec4(0.07f, 0.15f, 0.12f, 0.97f);
    colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.14f, 0.42f, 0.23f, 1.00f);
}

bool VertStyle::loadTextureFromFile(const char* filename, GLuint* out_texture, int* out_width, int* out_height)
{
    // Load from file
    int image_width = 0;
    int image_height = 0;
    unsigned char* image_data = stbi_load(filename, &image_width, &image_height, NULL, 4);
    if (image_data == NULL)
        return false;

    // Create a OpenGL texture identifier
    GLuint image_texture;
    glGenTextures(1, &image_texture);
    glBindTexture(GL_TEXTURE_2D, image_texture);

    // Setup filtering parameters for display
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Upload pixels into texture
#if defined(GL_UNPACK_ROW_LENGTH) && !defined(__EMSCRIPTEN__)
    glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
#endif
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image_width, image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_data);
    stbi_image_free(image_data);

    *out_texture = image_texture;
    *out_width = image_width;
    *out_height = image_height;

    return true;
}

void VertStyle::setupWindowIcon() {
    GLFWimage images[1];
    images[0].pixels = stbi_load("icon.png", &images[0].width, &images[0].height, 0, 4);

    glfwSetWindowIcon(VertShared::Window, 1, images);

    stbi_image_free(images[0].pixels);
}