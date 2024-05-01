#include <VertMainMenu.h>
#include <VertSettings.h>

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

		ImGui::MenuItem("Show Dear ImGui Demo", "F11", &GET_SETTING(show_demo));
		ImGui::MenuItem("Show FPS Counter", nullptr, &GET_SETTING(show_fps));
		ImGui::MenuItem("VSync", nullptr, &GET_SETTING(vsync));

		ImGui::EndMenu();
	}

	ImGui::EndMainMenuBar();
}