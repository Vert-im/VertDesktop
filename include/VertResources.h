#pragma once
#include <imgui.h>
#include <GLFW/glfw3.h>
#include <VertShared.h>
#include <map>
#include <string>


class VertTexture {
public:
	GLuint data;
	ImVec2 size;
};


#define LOAD_VERT_TEXTURE(path, name, id) \
	textures[name] = new VertTexture(); \
	int w_out_##id; \
	int h_out_##id; \
	loadTextureFromFile(path, &textures[name]->data, &w_out_##id, &h_out_##id); \
	textures[name]->size = {w_out_##id * 1.f, h_out_##id * 1.f};


#define GET_VERT_TEXTURE_DATA(name) VertResources::get()->textures[name]->data

#define GET_VERT_TEXTURE_SIZE(name) VertResources::get()->textures[name]->size


class VertResources {
public:
	inline static VertResources* instance;
	static VertResources* get();

	std::map<std::string, VertTexture*> textures = {};
	GLFWimage appIcon[1];
	ImFont* titleFont;

	void init();
	void loadAppIcon();
	void loadFonts();
	bool loadTextureFromFile(const char* filename, GLuint* out_texture, int* out_width, int* out_height);
};