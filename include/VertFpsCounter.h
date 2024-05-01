#pragma once
#include <imgui.h>
#include <GLFW/glfw3.h>
#include <VertShared.h>
#include <string>
#include <format>

class VertFpsCounter {
public:
	inline static VertFpsCounter* instance;
	static VertFpsCounter* get();

	bool show_ = false;

	void render();
};