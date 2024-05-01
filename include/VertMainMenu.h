#pragma once
#include <imgui.h>
#include <GLFW/glfw3.h>
#include <VertShared.h>
#include <VertAbout.h>
#include <VertFpsCounter.h>

class VertMainMenu {
public:
	inline static VertMainMenu* instance; 

	static VertMainMenu* get();

	void render();

};