#include "learning_state.h"

void LearningState::InitState(){

	Actor* actor;
	actor = new Actor();

	PositionComponent* position;
	position = new PositionComponent(Vector3{ 0, 0, 0 }, Vector3{ (float)GetScreenWidth(),(float)GetScreenHeight(), 0 });

	SpriteComponent* sprite;
	sprite = new SpriteComponent(TextureRegistry::getInstance()->GrabTexture("SIMA1"));

	actor->AddComponent(position);

	actor->AddComponent(sprite);

	SystemManager::getInstance()->AddActor(actor);

	float buttonWidth = 200, buttonHeight = 100;
	CreateButton(GetScreenWidth() / 2 - buttonWidth / 2, GetScreenHeight() / 2.5, buttonWidth, buttonHeight, "Simulate", "buton", [](Actor* actor) {
		ContextState::getInstance()->SetState(new SimulationState());
		ContextState::getInstance()->InitState();
		});

	CreateButton(GetScreenWidth() / 2 - buttonWidth / 2, GetScreenHeight() / 1.5, buttonWidth, buttonHeight, "Learn", "buton", [](Actor* actor) {
		ContextState::getInstance()->SetState(new LearningState());
		ContextState::getInstance()->InitState();
		});

	
	SpriteRendererSystem* renderer = new SpriteRendererSystem();

	SystemManager::getInstance()->AddSystem(renderer);

	ButtonMenuSystem* system = new ButtonMenuSystem();

	SystemManager::getInstance()->AddSystem(system);


}