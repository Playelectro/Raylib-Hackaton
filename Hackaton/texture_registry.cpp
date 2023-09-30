#include "texture_registry.h"

TextureRegistry* TextureRegistry::instancePtr = NULL;

void TextureRegistry::LoadImg(const char* path) {
	std::string path_m = std::string(path);

	Texture2D pot = LoadTexture(path_m.append(".png").c_str());

	
	textures[path] = pot;
}

Texture2D TextureRegistry::GrabTexture(const char* path) {

	if (textures.find(path) != textures.end()) {
		TextureRegistry::getInstance()->LoadImg(path);
	}
	// TODO Add a recent textures folder that keeps the texture loaded to the gpu in case of instancing
	return textures[path];
}