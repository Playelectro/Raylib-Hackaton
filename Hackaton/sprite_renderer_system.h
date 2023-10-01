#pragma once

#include "system.h"
#include "position_component.h"
#include "sprite_component.h"

class SpriteRendererSystem :public System
{
	public:

	SpriteRendererSystem() {
		requirements.push_back(typeid(PositionComponent).name());
		requirements.push_back(typeid(SpriteComponent).name());
	}


	void doLogic(std::vector<Actor*> actors, int current) override;
};