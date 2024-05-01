#include <VertKeys.h>

VertKeys* VertKeys::get() {
	if (instance == nullptr) {
		instance = new VertKeys();
	}
	return instance;
}

void VertKeys::update() {
    if (ImGui::IsKeyChordPressed(ImGuiKey_ModCtrl | ImGuiKey_Q)) {
        glfwSetWindowShouldClose(VertShared::Window, 1);
    }


    if (ImGui::IsKeyPressed(ImGuiKey_F11, false)) {
        VertShared::ShowDemo = !VertShared::ShowDemo;
    }
}