#pragma once
#include <raylib.h>
#include "component.h"
#include <functional>
#include "actor.h"

class MenuButtonComponent : public Component
{
public:

	std::function<void(Actor*)> onClick;

	std::string text;

	std::string texture;

	int font_size;


	MenuButtonComponent(std::string text, std::string texture, int font_size,  std::function<void(Actor*)> lambda)
	{
		this->onClick = lambda;
		this->text = text;
		this->texture = texture;

		this->font_size = font_size;
	}

};
