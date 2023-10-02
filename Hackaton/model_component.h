#pragma once

#include "component.h"
#include <raylib.h>

class ModelComponent : public Component {
public:

	Model model;

	ModelComponent(Model model) {
		this->model = model;
	}
};