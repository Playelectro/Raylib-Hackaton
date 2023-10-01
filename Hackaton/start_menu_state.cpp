#include "start_menu_states.h"

void StartMenuState::InitState() {
	float buttonWidth = 200, buttonHeight = 100;
	CreateButton(GetScreenWidth() / 2 - buttonWidth / 2, GetScreenHeight() / 2.5, buttonWidth, buttonHeight, "Simulate", [](Actor* actor) {
		ContextState::getInstance()->SetState(new SimulationState());
		ContextState::getInstance()->InitState();
		});

	CreateButton(GetScreenWidth() / 2 - buttonWidth / 2, GetScreenHeight() / 1.5, buttonWidth, buttonHeight, "Learn", [](Actor* actor) {
		ContextState::getInstance()->SetState(new LearningState());
		ContextState::getInstance()->InitState();
		});



	SpriteRendererSystem* renderer = new SpriteRendererSystem();

	SystemManager::getInstance()->AddSystem(renderer);

	ButtonMenuSystem* system = new ButtonMenuSystem();

	SystemManager::getInstance()->AddSystem(system);
}