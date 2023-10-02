#pragma once

#include "system.h"
#include "model_component.h"
#include <raylib.h>
#include "position_component.h"
#include "texture_registry.h"

class ModelRendererSystem : public System {
public:

	Camera camera;

	ModelRendererSystem() {
		requirements.push_back(typeid(PositionComponent).name());
		requirements.push_back(typeid(ModelComponent).name());

		camera = { 0 };
		camera.position = Vector3{ 0.0f, 0.0f, 0.0f };
		camera.target = Vector3{ 10.0f, 0.0f, 0.0f };
		camera.up = Vector3{ 0.0f, 1.0f, 0.0f };
		camera.fovy = 45.0f;
		camera.projection = CAMERA_PERSPECTIVE;

	}

	void doLogic(std::vector<Actor*> actors, int current) override;

	void Update() override;

};