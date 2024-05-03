#include <VertFormButton.h>
#include <VertResources.h>

bool VertWidgets::VertFormButton(const char* label, ImVec2 size) {
	ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, { 12, 12 });
	ImGui::PushStyleVar(ImGuiStyleVar_ItemInnerSpacing, { 20, 4 });

	auto ret = ImGui::Button(label, size);

	ImGui::PopStyleVar(2);

	return ret;
}