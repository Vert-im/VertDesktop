#include <VertFormTextInput.h>
#include <VertResources.h>

bool VertWidgets::VertFormTextInput(const char* name, const char* hint, char* buf, size_t buf_size, ImGuiInputTextFlags flags) {
	ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, { 12, 12 });
	ImGui::PushStyleVar(ImGuiStyleVar_ItemInnerSpacing, { 20, 4 });

	auto ret = ImGui::InputTextWithHint(name, hint, buf, buf_size, flags);

	ImGui::PopStyleVar(2);

	return ret;
}