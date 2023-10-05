#include "physics_system.h"

void PhysicsSystem::doLogic(std::vector<Actor*> actors, int current) {
	
	PositionComponent* actor_position_a = actors[current]->GetComponent<PositionComponent>();

	PhysicsComponent* actor_pshysics_a = actors[current]->GetComponent<PhysicsComponent>();

	ModelComponent* model_component_a = actors[current]->GetComponent<ModelComponent>();

	Vector3 rez = actor_pshysics_a->velocity;

	//if(actor_pshysics_a->density > )

	for (int i = 0; i < actors.size(); i++) {
		if (i == current)
			continue;

		PositionComponent* actor_position_b = actors[i]->GetComponent<PositionComponent>();

		PhysicsComponent* actor_pshysics_b = actors[i]->GetComponent<PhysicsComponent>();

		ModelComponent* model_component_b = actors[current]->GetComponent<ModelComponent>();

		float distance = (float) distanceVectors(actor_position_a->transform.translation, actor_position_b->transform.translation);

		float force = 0;
		
		if (!CheckCollisionSpheres(actor_position_a->transform.translation, model_component_a->radius, actor_position_b->transform.translation, model_component_b->radius)) {
			force = -1 / actor_pshysics_a->mass * actor_pshysics_b->mass / (distance * distance);

			Vector3 vector = toScalarVector(subtractVectors(actor_position_a->transform.translation, actor_position_b->transform.translation), 1 / distance);

			vector = toScalarVector(vector, force);

			rez = addVectors(rez, vector);
		}else{
			/*if (actor_pshysics_a->type == GAS && actor_pshysics_b->type == SOLID)
			{
				float aux = actor_pshysics_a->mass;
				actor_pshysics_a->mass += actor_pshysics_b->mass;
				actor_pshysics_a->radius = ((-1 / actor_pshysics_a->mass * actor_pshysics_b->mass / (distance * distance)) * actor_pshysics_a->radius) / force;
				actor_pshysics_a->volume = (4 * PI * (actor_pshysics_a->radius * actor_pshysics_a->radius * actor_pshysics_a->radius)) / 3;
				actor_pshysics_a->density = actor_pshysics_a->mass / actor_pshysics_a->volume;
				actor_pshysics_a->velocity = toScalarVector(Vector3Add(toScalarVector(actor_pshysics_a->velocity, aux), toScalarVector(actor_pshysics_b->velocity, actor_pshysics_b->mass)),  1/actor_pshysics_a->mass);
				actors[i]->markDeletion = true;
			}
			*/
			if (model_component_a->radius >= model_component_b->radius) {
				int aux = actor_pshysics_a->mass;
				actor_pshysics_a->mass += actor_pshysics_b->mass;
				actor_pshysics_a->radius = ((-1 / actor_pshysics_a->mass * actor_pshysics_b->mass / (distance * distance)) * model_component_a->radius) / force;
				actor_pshysics_a->velocity = toScalarVector(Vector3Add(toScalarVector(actor_pshysics_a->velocity, aux), toScalarVector(actor_pshysics_b->velocity, actor_pshysics_b->mass)), 1/actor_pshysics_a->mass);
				actors[i]->markDeletion = true;
			}
		}

		
	}

	actor_pshysics_a->velocity = rez;

	rez = addVectors(actor_position_a->transform.translation, toScalarVector(rez, GetFrameTime()));
	
	
	actor_position_a->transform.translation = rez;
	

	//TODO : ON COLLISION MERGE THE PLANETS

}