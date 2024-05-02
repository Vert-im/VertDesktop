#pragma once
#include <ranges>
#include <algorithm>
#include <cstdint>
#include <cmath>
#include <math.h>
#include <imgui.h>
#include <GLFW/glfw3.h>
#include <VertShared.h>

class VertAbout {
public:
	inline static VertAbout* instance;
	static VertAbout* get();

	bool show_ = false;
	bool focused = false;
	float tintModifier = 1.0f;
	const char* windowTitle = "Vert / About";

	void render();
	void show();
};