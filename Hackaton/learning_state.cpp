#include "learning_state.h"
#include "planets_state.h"
#include "sateliti.h"

void LearningState::InitState(){

	Actor* actor;
	actor = new Actor();

	PositionComponent* position;
	position = new PositionComponent(Vector3{ 0, 0, 0 }, Vector3{ (float)GetScreenWidth(),(float)GetScreenHeight(), 0 });

	SpriteComponent* sprite;
	sprite = new SpriteComponent(TextureRegistry::getInstance()->GrabTexture(std::string("SIMA")),0);

	actor->AddComponent(position);

	actor->AddComponent(sprite);

	SystemManager::getInstance()->AddActor(actor);
	
	float buttonWidth = 200, buttonHeight = 100;
	CreateButton((GetScreenWidth() / 2 - buttonWidth / 2)-200, GetScreenHeight() / 2-150, buttonWidth, buttonHeight,22,"Planete", "button", [](Actor* actor) {
		ContextState::getInstance()->SetState(new PlanetState());
		ContextState::getInstance()->InitState();
		});

	CreateButton((GetScreenWidth() / 2 - buttonWidth / 2)-200, GetScreenHeight() / 2, buttonWidth, buttonHeight, 22,"Sateliti", "button", [](Actor* actor) {
		ContextState::getInstance()->SetState(new Sateliti());
		ContextState::getInstance()->InitState();
		});

	CreateButton((GetScreenWidth() / 2 - buttonWidth / 2)-200, GetScreenHeight() / 2+150, buttonWidth, buttonHeight, 22,"Chestii 1", "button", [](Actor* actor) {
		ContextState::getInstance()->SetState(new PlanetState());
		ContextState::getInstance()->InitState();
		});
	
	CreateButton((GetScreenWidth() / 2 - buttonWidth / 2)+200, GetScreenHeight() / 2-150, buttonWidth, buttonHeight, 22,"Chestii 2", "button", [](Actor* actor) {
		ContextState::getInstance()->SetState(new PlanetState());
		ContextState::getInstance()->InitState();
		});

	CreateButton((GetScreenWidth() / 2 - buttonWidth / 2)+200, GetScreenHeight() / 2, buttonWidth, buttonHeight,22 ,"Chestii 3", "button", [](Actor* actor) {
		ContextState::getInstance()->SetState(new PlanetState());
		ContextState::getInstance()->InitState();
		});

	CreateButton((GetScreenWidth() / 2 - buttonWidth / 2)+200, GetScreenHeight() / 2+150, buttonWidth, buttonHeight, 22, "Chestii 4", "button", [](Actor* actor) {
		ContextState::getInstance()->SetState(new PlanetState());
		ContextState::getInstance()->InitState();
		});

	CreateButton(GetScreenWidth() / 11 - buttonWidth / 2, GetScreenHeight() / 1.15, buttonWidth, buttonHeight, 30, "Back", "button", [](Actor* actor) {
		ContextState::getInstance()->RegressState();
		ContextState::getInstance()->InitState();
		});
	
	SpriteRendererSystem* renderer = new SpriteRendererSystem();

	SystemManager::getInstance()->AddSystem(renderer);

	ButtonMenuSystem* system = new ButtonMenuSystem();

	SystemManager::getInstance()->AddSystem(system);
}