#include "physics_system.h"

void PhysicsSystem::doLogic(std::vector<Actor*> actors, int current) {
	
	PositionComponent* actor_position_a = actors[current]->GetComponent<PositionComponent>();

	PhysicsComponent* actor_pshysics_a = actors[current]->GetComponent<PhysicsComponent>();

	Vector3 rez;

	for (int i = 0; i < actors.size(); i++) {
		PositionComponent* actor_position_b = actors[i]->GetComponent<PositionComponent>();

		PhysicsComponent* actor_pshysics_b = actors[i]->GetComponent<PhysicsComponent>();

		float distance = distanceVectors(actor_position_a->transform.translation, actor_position_b->transform.translation);

		float force = G * actor_pshysics_a->mass * actor_pshysics_b->mass / (distance * distance);
	}
}