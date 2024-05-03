#include <VertSettings.h>

VertSettings* VertSettings::get() {
	if (instance == nullptr) {
		instance = new VertSettings();
	}
	return instance;
}

void VertSettings::init() {
	_ = new VertSettingsState();
	load();
}

void VertSettings::load() {
	try {
		std::ifstream f("vert_config.json");
		state = nlohmann::json::parse(f);
	}
	catch (std::exception& ex) {
		spdlog::error("Failed to load config from file: {}", ex.what());
	}

	GLFWmonitor* MyMonitor = glfwGetPrimaryMonitor();

	const GLFWvidmode* mode = glfwGetVideoMode(MyMonitor);

	LOAD_SETTING(vsync, false);
	LOAD_SETTING(show_fps, false);
	LOAD_SETTING(show_demo, false);
	LOAD_SETTING(maximize, false);
	LOAD_SETTING(window_pos_x, mode->width / 2 - 640);
	LOAD_SETTING(window_pos_y, mode->height / 2 - 360);
	LOAD_SETTING(window_size_x, 1280);
	LOAD_SETTING(window_size_y, 720);
	LOAD_SETTING(token, "");
}

void VertSettings::save() {
	std::ofstream f("vert_config.json", std::ios::trunc);

	SAVE_SETTING(vsync);
	SAVE_SETTING(show_fps);
	SAVE_SETTING(show_demo);
	SAVE_SETTING(maximize);
	SAVE_SETTING(window_pos_x);
	SAVE_SETTING(window_pos_y);
	SAVE_SETTING(window_size_x);
	SAVE_SETTING(window_size_y);
	SAVE_SETTING(token);

	f << state.dump();
	f.close();
}