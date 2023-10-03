#pragma once
#include "app_state.h"
#include "actor.h"
#include "position_component.h"
#include "sprite_component.h"
#include "system_manager.h"
#include "texture_registry.h"
#include "sprite_renderer_system.h"
#include "context_state.h"
#include "simulation_state.h"
#include "button_menu_system.h"
#include "model_registry.h"
#include "model_component.h"

class LearningState : public AppState{
public:
	void InitState() override;

};

