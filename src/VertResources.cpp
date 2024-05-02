#include <VertResources.h>
#include "stb_image.h"


VertResources* VertResources::get() {
    if (instance == nullptr) {
        instance = new VertResources();
    }
    return instance;
}


void VertResources::init() {
    loadImages();
    loadAppIcon();
    loadFonts();
}


void VertResources::loadImages() {
    LOAD_VERT_TEXTURE("images/icon.png", "icon.png", icon);
}


void VertResources::loadAppIcon() {
    appIcon[0].pixels = stbi_load("images/icon.png", &appIcon[0].width, &appIcon[0].height, 0, 4);
}


void VertResources::loadFonts() {
    auto io = ImGui::GetIO();

    io.Fonts->AddFontFromFileTTF("fonts/consola.ttf", 16.0f, nullptr, io.Fonts->GetGlyphRangesCyrillic());
    titleFont = io.Fonts->AddFontFromFileTTF("fonts/consola.ttf", 32.0f, nullptr, io.Fonts->GetGlyphRangesCyrillic());
}


bool VertResources::loadTextureFromFile(const char* filename, GLuint* out_texture, int* out_width, int* out_height) {
    // Load from file
    int image_width = 0;
    int image_height = 0;
    unsigned char* image_data = stbi_load(filename, &image_width, &image_height, NULL, 4);
    if (image_data == NULL)
        return false;

    // Create a OpenGL texture identifier
    GLuint image_texture;
    glGenTextures(1, &image_texture);
    glBindTexture(GL_TEXTURE_2D, image_texture);

    // Setup filtering parameters for display
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Upload pixels into texture
#if defined(GL_UNPACK_ROW_LENGTH) && !defined(__EMSCRIPTEN__)
    glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
#endif
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image_width, image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_data);
    stbi_image_free(image_data);

    *out_texture = image_texture;

    *out_width = image_width;
    *out_height = image_height;

    return true;
}