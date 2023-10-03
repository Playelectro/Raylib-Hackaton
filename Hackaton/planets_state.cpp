#include "planets_state.h"
void PlanetState::InitState() {

	Actor* actor;
	actor = new Actor();

	PositionComponent* position;
	position = new PositionComponent(Vector3{ 0, 0, 0 }, Vector3{ (float)GetScreenWidth(),(float)GetScreenHeight(), 0 });

	SpriteComponent* sprite;
	sprite = new SpriteComponent(TextureRegistry::getInstance()->GrabTexture(std::string("cosmos")), 0);

	actor->AddComponent(position);

	actor->AddComponent(sprite);

	SystemManager::getInstance()->AddActor(actor);

	SpriteRendererSystem* renderer = new SpriteRendererSystem();

	float buttonWidth = 100, buttonHeight = 50;
	CreateButton(GetScreenWidth() / 11 - buttonWidth / 2, GetScreenHeight() / 1.15, buttonWidth, buttonHeight, 30, "Back", "button", [](Actor* actor) {
		ContextState::getInstance()->RegressState();
		ContextState::getInstance()->InitState();
		});

	actor = new Actor();

	ModelComponent* model= new ModelComponent(ModelRegistry::getInstance()->GrabModel("RubberDuck_LOD0.obj"), TextureRegistry::getInstance()->GrabTexture("RubberDuck_AlbedoTransparency"));

	position = new PositionComponent(Vector3{ 10, 0, 3 }, Quaternion{ 0.0, 1.0, 0.0, 3 }, Vector3{ 0.1,0.1,0.1 });

	SystemManager::getInstance()->AddSystem(renderer);

	ButtonMenuSystem* system = new ButtonMenuSystem();

	SystemManager::getInstance()->AddSystem(system);

}