#include "learning_state.h"
#include "planets_state.h"
#include "sateliti.h"

void LearningState::InitState(){

	Actor* actor;
	actor = new Actor();

	PositionComponent* position;
	position = new PositionComponent(Vector3{ 0, 0, 0 }, Vector3{ (float)GetScreenWidth(),(float)GetScreenHeight(), 0 });

	SpriteComponent* sprite;
	sprite = new SpriteComponent(TextureRegistry::getInstance()->GrabTexture("SIMA"),0);

	actor->AddComponent(position);

	actor->AddComponent(sprite);

	SystemManager::getInstance()->AddActor(actor);
	
	float buttonWidth = 100, buttonHeight = 50;
	CreateButton((GetScreenWidth() / 2 - buttonWidth / 2)-100, GetScreenHeight() / 2-100, buttonWidth, buttonHeight, "Planete", "buton", [](Actor* actor) {
		ContextState::getInstance()->SetState(new PlanetState());
		ContextState::getInstance()->InitState();
		});

	CreateButton((GetScreenWidth() / 2 - buttonWidth / 2)-100, GetScreenHeight() / 2, buttonWidth, buttonHeight, "Sateliti", "buton", [](Actor* actor) {
		ContextState::getInstance()->SetState(new Sateliti());
		ContextState::getInstance()->InitState();
		});

	CreateButton((GetScreenWidth() / 2 - buttonWidth / 2)-100, GetScreenHeight() / 2+100, buttonWidth, buttonHeight, "Chestii 1", "buton", [](Actor* actor) {
		ContextState::getInstance()->SetState(new PlanetState());
		ContextState::getInstance()->InitState();
		});
	
	CreateButton((GetScreenWidth() / 2 - buttonWidth / 2)+100, GetScreenHeight() / 2-100, buttonWidth, buttonHeight, "Chestii 2", "buton", [](Actor* actor) {
		ContextState::getInstance()->SetState(new PlanetState());
		ContextState::getInstance()->InitState();
		});

	CreateButton((GetScreenWidth() / 2 - buttonWidth / 2)+100, GetScreenHeight() / 2, buttonWidth, buttonHeight, "Chestii 3", "buton", [](Actor* actor) {
		ContextState::getInstance()->SetState(new PlanetState());
		ContextState::getInstance()->InitState();
		});

	CreateButton((GetScreenWidth() / 2 - buttonWidth / 2)+100, GetScreenHeight() / 2+100, buttonWidth, buttonHeight, "Chestii 4", "buton", [](Actor* actor) {
		ContextState::getInstance()->SetState(new PlanetState());
		ContextState::getInstance()->InitState();
		});

	CreateButton((GetScreenWidth() / 2 - buttonWidth / 2) + 100, GetScreenHeight() / 2 + 100, buttonWidth, buttonHeight, "Chestii 4", "buton", [](Actor* actor) {
		ContextState::getInstance()->SetState(new PlanetState());
		ContextState::getInstance()->InitState();
		});
	
	SpriteRendererSystem* renderer = new SpriteRendererSystem();

	SystemManager::getInstance()->AddSystem(renderer);

	ButtonMenuSystem* system = new ButtonMenuSystem();

	SystemManager::getInstance()->AddSystem(system);

}