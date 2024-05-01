#include <VertFpsCounter.h>
#include <VertSettings.h>

VertFpsCounter* VertFpsCounter::get() {
	if (instance == nullptr) {
		instance = new VertFpsCounter();
	}
	return instance;
}

void VertFpsCounter::render() {
	show_ = GET_SETTING(show_fps);

	if (show_) {
		ImGui::BeginMainMenuBar();

		ImGui::MenuItem(
			std::format("FPS: {:.0f}", ImGui::GetIO().Framerate).c_str(), 
			nullptr, nullptr, false
		);

		ImGui::EndMainMenuBar();
	}

}