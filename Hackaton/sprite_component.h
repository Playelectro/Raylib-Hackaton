#pragma once

#include "component.h"
#include <raylib.h>

class SpriteComponent : public Component {
public:
	Texture2D texture;

	SpriteComponent(Texture2D texture) {
		this->texture = texture;
	}
};