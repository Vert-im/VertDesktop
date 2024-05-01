#pragma once
#include <imgui.h>
#include <GLFW/glfw3.h>
#include <VertShared.h>

class VertStyle {
public:
	inline static VertStyle* instance;
	static VertStyle* get();

	void setup();
	void updateColors();
	bool loadTextureFromFile(const char* filename, GLuint* out_texture, int* out_width, int* out_height);
	void setupWindowIcon();
};