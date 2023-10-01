#include "start_menu_states.h"

void StartMenuState::InitState() {
	float buttonWidth = 100, buttonHeight = 50;
	CreateButton(GetScreenWidth() / 2 - buttonWidth / 2, GetScreenHeight() / 2.5, buttonWidth, buttonHeight, [](Actor* actor) {
		ContextState::getInstance()->SetState(new SimulationState());
		ContextState::getInstance()->InitState();
		});

	CreateButton(GetScreenWidth() / 2 - buttonWidth / 2, GetScreenHeight() / 1.5, buttonWidth, buttonHeight, [](Actor* actor) {
		ContextState::getInstance()->SetState(new LearningState());
		ContextState::getInstance()->InitState();
		});



	ButtonMenuSystem* system = new ButtonMenuSystem();

	SystemManager::getInstance()->AddSystem(system);

	SpriteRendererSystem* renderer = new SpriteRendererSystem();

	SystemManager::getInstance()->AddSystem(renderer);
}