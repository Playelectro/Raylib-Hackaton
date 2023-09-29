#include "print_system.h"


void PrintSystem::doLogic(std::vector<Actor*> actors, int current) {
		PositionComponent* comp = actors[current]->GetComponent<PositionComponent>();

		comp->transform.translation = addVectors(comp->transform.translation, Vector3{ 0.0,1.0,0.0 });

		std::cout << comp->transform.translation.x << " " << comp->transform.translation.y << " " << comp->transform.translation.z << std::endl;
}