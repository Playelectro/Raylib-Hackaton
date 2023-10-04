#pragma once
#include "app_state.h"
#include "ui_util.h"
#include "actor.h"
#include "position_component.h"
#include "sprite_component.h"
#include "system_manager.h"
#include "texture_registry.h"
#include "sprite_renderer_system.h"
#include "button_menu_system.h"
#include "context_state.h"
#include "model_renderer_system.h"
#include "physics_system.h"
#include "camera_component.h"
#include "model_registry.h"
#include "camera_controls_system.h"
#include "spawn_planets_system.h"

class SimulationState : public AppState{
public:
	void InitState() override;

};

