#include "test_state.h"

void TestState::InitState() {

	Actor* actor;
	actor = new Actor();

	PhysicsComponent* physics = new PhysicsComponent(200, 100, Vector3{0, 0, 0});

	ModelComponent* model = new ModelComponent(ModelRegistry::getInstance()->GrabModel("planeta2.gltf"), TextureRegistry::getInstance()->GrabTexture("textura"));

	PositionComponent* position = new PositionComponent(Vector3{ 10, 0, 0 });

	actor->AddComponent(physics);

	actor->AddComponent(model);

	actor->AddComponent(position);

	SystemManager::getInstance()->AddActor(actor);

	PhysicsSystem* renderer = new PhysicsSystem();

	SystemManager::getInstance()->AddSystem(renderer);

	ModelRendererSystem* system = new ModelRendererSystem();

	SystemManager::getInstance()->AddSystem(system);
}