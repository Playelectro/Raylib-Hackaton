#include "spawn_planets_system.h"

void SpawnPlanetsSystem::doLogic(std::vector<Actor*> actors, int current) {
	if (isSpawning && IsMouseButtonPressed(0)) {

		CameraComponent* camera = actors[current]->GetComponent<CameraComponent>();

		Ray result = GetMouseRay(GetMousePosition(), camera->camera);

		
	}
}