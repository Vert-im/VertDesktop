#include <VertStyle.h>
#include <VertResources.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

VertStyle* VertStyle::get() {
    if (instance == nullptr) {
        instance = new VertStyle();
    }
    return instance;
}

void VertStyle::setup() {
    updateColors();

    auto style = ImGui::GetStyle();

    style.WindowRounding = 4;
    style.FrameRounding = 3;
    style.PopupRounding = 3;
    style.WindowTitleAlign.x = .5f;
}

void VertStyle::updateColors() {
    ImVec4* colors = ImGui::GetStyle().Colors;
    colors[ImGuiCol_NavHighlight] = ImVec4(0.69f, 1.00f, 0.78f, 0.0f);

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

void VertStyle::setupWindowIcon() {
    glfwSetWindowIcon(VertShared::Window, 1, VertResources::get()->appIcon);
}