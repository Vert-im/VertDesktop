#include <VertMainMenu.h>

VertMainMenu* VertMainMenu::get() {
	if (instance == nullptr) {
		instance = new VertMainMenu();
	}
	return instance;
}

void VertMainMenu::render() {
	ImGui::BeginMainMenuBar();

	if (ImGui::BeginMenu("Vert")) {

		if (ImGui::MenuItem("About Vert")) {
			VertAbout::get()->show();
		}

		if (ImGui::MenuItem("Exit", "Ctrl + Q")) {
			glfwSetWindowShouldClose(VertShared::Window, 1);
		}

		ImGui::EndMenu();
	}

	if (ImGui::BeginMenu("Tools")) {

		ImGui::MenuItem("Show Dear ImGui Demo", "F11", &VertShared::ShowDemo);
		ImGui::MenuItem("Show FPS Counter", nullptr, &VertFpsCounter::get()->show_);
		ImGui::MenuItem("VSync", nullptr, &VertShared::VSync);

		ImGui::EndMenu();
	}

	ImGui::EndMainMenuBar();
}