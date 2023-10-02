#pragma once

#include "app_state.h"
#include "actor.h"
#include "position_component.h"
#include "system_manager.h"
#include "model_registry.h"
#include "model_component.h"
#include "model_renderer_system.h"
#include "physics_component.h"
#include "physics_system.h"

/// aici ar fi prima varianta
class TestState : public AppState {
public:
	void InitState() override;

};