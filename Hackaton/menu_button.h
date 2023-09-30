#pragma once
#include <raylib.h>
#include "component.h"

class MenuButton : public Component
{
public:

	float width, height;

	MenuButton(float width, float height)
	{
		this->width = width;
		this->height = height;
	}

	MenuButton(float size)
	{
		this->width = size;
		this->height = size;
	}

	

};
