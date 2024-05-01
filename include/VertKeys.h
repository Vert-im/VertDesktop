#pragma once
#include <imgui.h>
#include <GLFW/glfw3.h>
#include <VertShared.h>

class VertKeys {
public:
	inline static VertKeys* instance;

	static VertKeys* get();

	void update();

};