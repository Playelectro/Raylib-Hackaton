#include "texture_registry.h"

TextureRegistry* TextureRegistry::instancePtr = NULL;

bool TextureRegistry::LoadImg(const char* path) {
	std::string path_m = std::string(path);

	Image pot = LoadImage(path_m.append(".png").c_str());

	if (pot.data != NULL) {
		textures[path] = pot;
	}
	return pot.data != NULL;
}

Texture2D TextureRegistry::GrabTexture(const char* path) {

	if (textures.find(path) != textures.end()) {
		if (!TextureRegistry::getInstance()->LoadImg(path)) {
			return LoadTextureFromImage(textures["default"]);;
		}
	}
	// TODO Add a recent textures folder that keeps the texture loaded to the gpu in case of instancing
	return LoadTextureFromImage(textures[path]);
}