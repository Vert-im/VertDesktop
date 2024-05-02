#include <VertAbout.h>
#include <VertResources.h>

VertAbout* VertAbout::get() {
    if (instance == nullptr) {
        instance = new VertAbout();
    }
    return instance;
}

void VertAbout::render() {
    ImVec2 center = ImGui::GetMainViewport()->GetCenter();
    tintModifier = std::ranges::clamp(sinf((float)ImGui::GetTime() * 3.f), 0.5f, 1.f); // Lil animation

    //tintModifier = 1.f;

    if (show_) {
        ImGui::Begin(windowTitle, &show_, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse);

        auto size = ImGui::GetWindowSize();

        ImGui::SetWindowPos({ center.x - size.x / 2.f, center.y - size.y / 2.f });

        ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, { 8, 20 });
        ImGui::PushFont(VertResources::get()->titleFont);

        ImGui::Image(
            (void*)(intptr_t)GET_VERT_TEXTURE_DATA("icon.png"), 
            ImVec2(32, 32), {0, 0}, {1, 1}, 
            {tintModifier, tintModifier, tintModifier, 1}
        );

        ImGui::SameLine();

        ImGui::AlignTextToFramePadding();

        ImGui::Text("About Vert");
        ImGui::PopFont();

        ImGui::AlignTextToFramePadding();

        ImGui::Text("Instant Messenger made by Relative & SsNiPeR1 & fakeesp");
        ImGui::Text("2024");

        ImGui::TextDisabled("TODO: License");

        ImGui::PopStyleVar();

        if (ImGui::Button("OK", ImVec2(ImGui::GetWindowSize().x - ImGui::GetStyle().WindowPadding.x * 2, 0))) {
            show_ = false;
        }

        if ((
            ImGui::IsKeyPressed(ImGuiKey_Enter, false) || 
            ImGui::IsKeyPressed(ImGuiKey_Escape, false) ||
            ImGui::IsKeyPressed(ImGuiKey_KeypadEnter, false)) 
            && ImGui::IsWindowFocused()) {
            show_ = false;
        }

        ImGui::SetItemDefaultFocus();

        ImGui::End();
    }
}

void VertAbout::show() {
    show_ = true;
}