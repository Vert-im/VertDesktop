#include <VertFormTextInput.h>
#include <VertResources.h>

bool VertWidgets::VertFormTextInput(const char* name, const char* hint, char* buf, size_t buf_size, ImGuiInputTextFlags flags) {
	ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, { 12, 12 });
	ImGui::PushStyleVar(ImGuiStyleVar_ItemInnerSpacing, { 20, 4 });
	ImGui::PushStyleColor(ImGuiCol_TextDisabled, ImVec4(0.29f, 0.78f, 0.51f, 0.54f));

	ImGui::PushItemWidth(-1);

	auto ret = ImGui::InputTextWithHint(name, hint, buf, buf_size, flags);

	ImGui::PopItemWidth();

	ImGui::PopStyleColor();

	ImGui::PopStyleVar(2);

	return ret;
}