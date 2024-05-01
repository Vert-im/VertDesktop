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

	LOAD_SETTING(vsync, false);
	LOAD_SETTING(show_fps, false);
	LOAD_SETTING(show_demo, false);
	LOAD_SETTING(maximize, false);
}

void VertSettings::save() {
	std::ofstream f("vert_config.json", std::ios::trunc);

	SAVE_SETTING(vsync);
	SAVE_SETTING(show_fps);
	SAVE_SETTING(show_demo);
	SAVE_SETTING(maximize);

	f << state.dump();
	f.close();
}