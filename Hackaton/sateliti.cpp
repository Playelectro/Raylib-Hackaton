#include "sateliti.h"
#include "sateliti_naturali.h"
#include "sateliti_artificiali.h"

void Sateliti::InitState() {

	Actor* actor;
	actor = new Actor();

	PositionComponent* position;
	position = new PositionComponent(Vector3{ 0, 0, 0 }, Vector3{ (float)GetScreenWidth(),(float)GetScreenHeight(), 0 });

	SpriteComponent* sprite;
	sprite = new SpriteComponent(TextureRegistry::getInstance()->GrabTexture(std::string("SIMA")), 0);

	actor->AddComponent(position);

	actor->AddComponent(sprite);

	SystemManager::getInstance()->AddActor(actor);

	float buttonWidth = 100, buttonHeight = 50;
	CreateButton((GetScreenWidth() / 2 - buttonWidth / 2) - 100, GetScreenHeight() / 2, buttonWidth, buttonHeight, "Sateliti Naturali", "button", [](Actor* actor) {
		ContextState::getInstance()->SetState(new SatelitiNaturali());
		ContextState::getInstance()->InitState();
		});
	
	CreateButton((GetScreenWidth() / 2 - buttonWidth / 2) + 100, GetScreenHeight() / 2, buttonWidth, buttonHeight, "Sateliti Artificiali", "button", [](Actor* actor) {
		ContextState::getInstance()->SetState(new SatelitiArtificiali());
		ContextState::getInstance()->InitState();
		});

	CreateButton(GetScreenWidth() / 11 - buttonWidth / 2, GetScreenHeight() / 1.15, buttonWidth, buttonHeight, 30, "Back", "button", [](Actor* actor) {
		ContextState::getInstance()->RegressState();
		ContextState::getInstance()->InitState();
		});

	SystemManager::getInstance()->AddActor(actor);

	SpriteRendererSystem* renderer = new SpriteRendererSystem();

	SystemManager::getInstance()->AddSystem(renderer);

	ButtonMenuSystem* system = new ButtonMenuSystem();

	SystemManager::getInstance()->AddSystem(system);


}
