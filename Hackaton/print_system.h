#pragma once
#include "system.h"
#include "position_component.h"
#include <iostream>
#include "util.h"

class PrintSystem : public System
{
	public:
		PrintSystem() {
			requirements.push_back(typeid(PositionComponent).name());
		}

		void doLogic(std::vector<Actor*> actors, int current) override;
};

