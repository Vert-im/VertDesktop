#pragma once
#include <iostream>
#include <fstream>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <VertShared.h>

#define LOAD_SETTING(key, fallback)              \
    if (state.contains(#key))           \
        _->key = state[#key];           \
	else                                \
		_->key = fallback

#define GET_SETTING(key) \
	VertSettings::get()->_->key

#define SET_SETTING(key, value) \
	VertSettings::get()->_->key = value

#define SAVE_SETTING(key) state[#key] = _->key;

class VertSettingsState {
public:
	bool vsync;
	bool show_demo;
	bool show_fps;
	bool maximize;
};

class VertSettings {
public:
	inline static VertSettings* instance;
	static VertSettings* get();

	nlohmann::json state;
	VertSettingsState* _;

	void init();
	void load();
	void save();
};