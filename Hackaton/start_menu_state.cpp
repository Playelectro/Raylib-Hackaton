#include "start_menu_states.h"

void StartMenuState::InitState() {
	float buttonWidth = 200, buttonHeight = 100;
	CreateButton(GetScreenWidth() / 2 - buttonWidth / 2, GetScreenHeight() / 2, buttonWidth, buttonHeight, [](Actor* actor) {
		ContextState::getInstance()->SetState(new SimulationState());
		ContextState::getInstance()->InitState();
		});


	ButtonMenuSystem* system = new ButtonMenuSystem();

	SystemManager::getInstance()->AddSystem(system);

	SpriteRendererSystem* renderer = new SpriteRendererSystem();

	SystemManager::getInstance()->AddSystem(renderer);
}