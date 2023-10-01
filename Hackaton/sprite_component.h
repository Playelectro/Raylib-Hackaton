#pragma once

#include "component.h"
#include <raylib.h>

class SpriteComponent : public Component {
public:
	Texture2D texture;
	bool stretch = false;

	SpriteComponent(Texture2D texture, bool stretch) {
		this->texture = texture;
		this->stretch = stretch;
	}
};