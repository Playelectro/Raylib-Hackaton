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


	MenuButtonComponent(std::string text, std::function<void(Actor*)> lambda)
	{
		this->onClick = lambda;
		this->text = text;
	}

};
