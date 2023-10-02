#include "simulation_state.h"

void SimulationState::InitState() {
	float buttonWidth=128, buttonHeight=64;
	float buttonWidthSq = 128, buttonHeightSq = 128;
	Actor* actor;
	actor = new Actor();

	PositionComponent* position;
	position = new PositionComponent(Vector3{ 0, 0, 0 }, Vector3{ (float)GetScreenWidth(),(float)GetScreenHeight(), 0 });

	SpriteComponent* sprite;
	sprite = new SpriteComponent(TextureRegistry::getInstance()->GrabTexture("space"), 0);

	actor->AddComponent(position);

	actor->AddComponent(sprite);

	SystemManager::getInstance()->AddActor(actor);

		CreateButton(GetScreenWidth() / 1.12 - buttonWidth / 2, GetScreenHeight() / 1.15, buttonWidth, buttonHeight, "", "buton", [](Actor* actor)
		{
				std::cout << "am fost apasat";
		});
		CreateButton(GetScreenWidth() / 2 - buttonWidthSq / 2, GetScreenHeight() / 2, buttonWidthSq, buttonHeightSq, "", "buton_planeta", [](Actor* actor2)
		{
				std::cout << "am fost apasat";
		});

	SpriteRendererSystem* renderer = new SpriteRendererSystem();

	SystemManager::getInstance()->AddSystem(renderer);

	ButtonMenuSystem* system = new ButtonMenuSystem();

	SystemManager::getInstance()->AddSystem(system);


}