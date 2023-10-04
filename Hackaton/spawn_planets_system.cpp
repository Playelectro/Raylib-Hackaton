#include "spawn_planets_system.h"

void SpawnPlanetsSystem::doLogic(std::vector<Actor*> actors, int current) {
	if (isSpawning && IsMouseButtonReleased(0)) {

		CameraComponent* camera = actors[current]->GetComponent<CameraComponent>();

		Ray ray = GetMouseRay(GetMousePosition(), camera->camera);
		
		RayCollision hit =  GetRayCollisionBox(ray, BoundingBox{-100,0,-100,100,0,100});

		addCelestialBody(hit.point, {0,0,0},1000, 1, "textura");

		isSpawning = false;
	}
}