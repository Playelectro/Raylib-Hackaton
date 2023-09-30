#pragma once
#include <raylib.h>
#include "component.h"
#include <functional>

class MenuButton : public Component
{
public:

	float width, height;

	std::function<void(Actor*)> onClick;


	MenuButton(float width, float height, std::function<void(Actor*)> lambda)
	{
		this->width = width;
		this->height = height;
		this->onClick = lambda;
	}

	MenuButton(float size, std::function<void(Actor*)> lambda)
	{
		this->width = size;
		this->height = size;
		this->onClick = lambda;
	}

	

};
