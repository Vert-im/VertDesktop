#include <VertFpsCounter.h>

VertFpsCounter* VertFpsCounter::get() {
	if (instance == nullptr) {
		instance = new VertFpsCounter();
	}
	return instance;
}

void VertFpsCounter::render() {

	if (show_) {
		ImGui::BeginMainMenuBar();

		ImGui::MenuItem(
			std::format("FPS: {:.0f}", ImGui::GetIO().Framerate).c_str(), 
			nullptr, nullptr, false
		);

		ImGui::EndMainMenuBar();
	}

}