#include "model_renderer_system.h"

void ModelRendererSystem::doLogic(std::vector<Actor*> actors, int current) {
	ModelComponent* model = actors[current]->GetComponent<ModelComponent>();
	PositionComponent* position = actors[current]->GetComponent<PositionComponent>();

	DrawSphere(position->transform.translation, 3, WHITE);

	//DrawModelEx(model->model, position->transform.translation, Vector3{ position->transform.rotation.x, position->transform.rotation.y, position->transform.rotation.z }, position->transform.rotation.w, position->transform.scale, WHITE);
}

void ModelRendererSystem::Update() {
	UpdateCamera(&camera, CAMERA_FIRST_PERSON);

	BeginMode3D(camera);
	for (int i = 0; i < actors.size(); i++) {
		doLogic(actors, i);
	}
	EndMode3D();
}