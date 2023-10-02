#pragma once

#include "component.h"
#include <raylib.h>

class ModelComponent : public Component {
public:

	Model model;
	Texture2D texture;

	ModelComponent(Model model, Texture2D texture) {
		this->model = model;
		this->texture = texture;

		model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
	}
};