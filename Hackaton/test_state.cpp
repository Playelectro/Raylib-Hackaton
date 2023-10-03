#include "test_state.h"

void TestState::InitState() {

	Actor* actor;
	actor = new Actor();

	PhysicsComponent* physics = new PhysicsComponent(200, 0.5, Vector3{0, 2.1, 0});

	ModelComponent* model = new ModelComponent(ModelRegistry::getInstance()->GrabModel(1,0.5,20,20), TextureRegistry::getInstance()->GrabTexture("textura"));

	PositionComponent* position = new PositionComponent(Vector3{ 10, 0, 3 });

	actor->AddComponent(physics);

	actor->AddComponent(model);

	actor->AddComponent(position);

	SystemManager::getInstance()->AddActor(actor);


	Actor* actor1;
	actor1 = new Actor();

	PhysicsComponent* physics2 = new PhysicsComponent(200, 0.5, Vector3{ 0, -2.1, 0 });

	ModelComponent* model2 = new ModelComponent(ModelRegistry::getInstance()->GrabModel(1, 0.5, 20, 20), TextureRegistry::getInstance()->GrabTexture("textura"));

	PositionComponent* position2 = new PositionComponent(Vector3{ 10, 0, -3 });

	actor1->AddComponent(physics2);

	actor1->AddComponent(model2);

	actor1->AddComponent(position2);

	SystemManager::getInstance()->AddActor(actor1);

	PhysicsSystem* renderer = new PhysicsSystem();

	SystemManager::getInstance()->AddSystem(renderer);

	ModelRendererSystem* system = new ModelRendererSystem();

	SystemManager::getInstance()->AddSystem(system);
}