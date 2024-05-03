#pragma once
#include <imgui.h>

namespace VertWidgets {
	bool VertFormTextInput(const char* name, const char* hint, char* buf, size_t buf_size, ImGuiInputTextFlags flags = 0);
}