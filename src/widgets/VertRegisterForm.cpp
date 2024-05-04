#include <VertRegisterForm.h>
#include <VertFormTextInput.h>
#include <VertFormButton.h>
#include <VertResources.h>

bool VertWidgets::VertRegisterForm() {
	ImVec2 center = ImGui::GetMainViewport()->GetCenter();

    ImGui::SetNextWindowSize({ 350, 0 });

    ImGui::Begin(
        "Vert / Register", nullptr, 
        // ImGuiWindowFlags_AlwaysAutoResize | 
        ImGuiWindowFlags_NoMove | 
        ImGuiWindowFlags_NoCollapse | 
        ImGuiWindowFlags_NoBackground |
        ImGuiWindowFlags_NoDecoration
    );

    auto size = ImGui::GetWindowSize();

    ImGui::SetWindowPos({ center.x - size.x / 2.f, center.y - size.y / 2.f });

    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, { 8, 20 });
    ImGui::PushFont(VertResources::get()->titleFont);

    ImGui::Image(
        (void*)(intptr_t)GET_VERT_TEXTURE_DATA("icon.png"),
        ImVec2(32, 32), { 0, 0 }, { 1, 1 },
        { 1, 1, 1, 1 }
    );

    ImGui::SameLine();

    ImGui::AlignTextToFramePadding();

    ImGui::Text("Register");
    ImGui::PopFont();

    ImGui::AlignTextToFramePadding();

    static char username[128] = "";
    VertWidgets::VertFormTextInput("##Register/Username", "Username", username, IM_ARRAYSIZE(username));

    static char email[128] = "";
    VertWidgets::VertFormTextInput("##Register/E-mail", "email@example.com", email, IM_ARRAYSIZE(email));

    static char password[256] = "";
    VertWidgets::VertFormTextInput("##Register/Password", "*****************", password, IM_ARRAYSIZE(password), ImGuiInputTextFlags_Password);

    ImGui::PopStyleVar();


    if (VertWidgets::VertFormButton("OK", ImVec2(-1, 0)) ||
        ((
        ImGui::IsKeyPressed(ImGuiKey_Enter, false) ||
        ImGui::IsKeyPressed(ImGuiKey_Escape, false) ||
        ImGui::IsKeyPressed(ImGuiKey_KeypadEnter, false))
        && ImGui::IsWindowFocused())) {
        // Nothing fr
    }

    ImGui::SetItemDefaultFocus();

    ImGui::End();

	return false;
}