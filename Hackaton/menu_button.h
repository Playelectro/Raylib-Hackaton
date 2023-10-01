#pragma once
#include <raylib.h>
#include "component.h"
#include <functional>
#include "actor.h"

class MenuButtonComponent : public Component
{
public:

	std::function<void(Actor*)> onClick;


	MenuButtonComponent(std::function<void(Actor*)> lambda)
	{
		this->onClick = lambda;
	}

};
