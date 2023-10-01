#pragma once
#include "app_state.h"
#include "ui_util.h"

/// aici ar fi prima varianta
class SimulationState : public AppState{
public:
	void InitState() override
	{
		std::cout << "AM SCHIMBAT STATEUL: YEYEYEY";
	}

};

