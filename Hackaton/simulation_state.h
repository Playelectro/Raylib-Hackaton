#pragma once
#include "app_state.h"
#include "ui_util.h"
#include "actor.h"
#include "position_component.h"
#include "sprite_component.h"
#include "system_manager.h"
#include "texture_registry.h"
#include "sprite_renderer_system.h"

/// aici ar fi prima varianta
class SimulationState : public AppState{
public:
	void InitState() override;

};

