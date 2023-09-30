#pragma once

#include <raylib.h>
#include <unordered_map>
#include <iostream>

class TextureRegistry {

private:
	std::unordered_map<const char*, Image> textures;

	static TextureRegistry* instancePtr;

    bool LoadImg(const char*);

	TextureRegistry() {
        this->LoadImg("default");
    }

public:
    TextureRegistry(const TextureRegistry& obj) = delete;

    static TextureRegistry* getInstance()
    {
        if (instancePtr == NULL)
        {
            instancePtr = new TextureRegistry();
            return instancePtr;
        }
        else
        {
            return instancePtr;
        }
    }

    Texture2D GrabTexture(const char*);
};