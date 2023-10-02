#include "sateliti_artificiali.h"

void SatelitiArtificiali::InitState() {

	Actor* actor;
	actor = new Actor();

	PositionComponent* position;
	position = new PositionComponent(Vector3{ 0, 0, 0 }, Vector3{ (float)GetScreenWidth(),(float)GetScreenHeight(), 0 });

	SpriteComponent* sprite;
	sprite = new SpriteComponent(TextureRegistry::getInstance()->GrabTexture("SIMA"), 0);

	actor->AddComponent(position);

	actor->AddComponent(sprite);

	SystemManager::getInstance()->AddActor(actor);

	float buttonWidth = 100, buttonHeight = 50;
	CreateButton((GetScreenWidth() / 2 - buttonWidth / 2) - 100, GetScreenHeight() / 2, buttonWidth, buttonHeight, "Back", "buton", [](Actor* actor) {
		ContextState::getInstance()->SetState(new Sateliti());
		ContextState::getInstance()->InitState();
		});

	SpriteRendererSystem* renderer = new SpriteRendererSystem();

	SystemManager::getInstance()->AddSystem(renderer);

	ButtonMenuSystem* system = new ButtonMenuSystem();

	SystemManager::getInstance()->AddSystem(system);

}