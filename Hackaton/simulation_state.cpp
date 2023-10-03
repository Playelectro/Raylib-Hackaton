#include "simulation_state.h"

void SimulationState::InitState() {
	float buttonWidth=128, buttonHeight=64;
	float buttonWidthSq = 64, buttonHeightSq = 64;

	// ADD BACKGROUND
	Actor* actor;
	actor = new Actor();

	PositionComponent* position;
	position = new PositionComponent(Vector3{ 0, 0, 0 }, Vector3{ (float)GetScreenWidth(),(float)GetScreenHeight(), 0 });

	SpriteComponent* sprite;
	sprite = new SpriteComponent(TextureRegistry::getInstance()->GrabTexture(std::string("space")), 0);

	actor->AddComponent(position);

	actor->AddComponent(sprite);

	SystemManager::getInstance()->AddActor(actor);

	// ADD PLAYER CAMERA
	Actor* player = new Actor();

	CameraComponent* camera = new CameraComponent({ 0,0,0 }, {0,0,0},90.0f);

	player->AddComponent(camera);

	SystemManager::getInstance()->AddActor(player);


	// ADD UI BUTTONS
		CreateButton(GetScreenWidth() / 16 - buttonWidthSq / 2, GetScreenHeight() / 25, buttonWidthSq, buttonHeightSq, "", "button_planeta", [](Actor* actor2)
		{
				std::cout << "am fost apasat";
		});
		CreateButton(GetScreenWidth() / 11 - buttonWidth / 2, GetScreenHeight() / 1.15, buttonWidth, buttonHeight, 30, "Back", "button", [](Actor* actor) {
			ContextState::getInstance()->RegressState();
			ContextState::getInstance()->InitState();
			});


	// ADD SYSTEMS
	SpriteRendererSystem* renderer = new SpriteRendererSystem();

	SystemManager::getInstance()->AddSystem(renderer);

	ButtonMenuSystem* system = new ButtonMenuSystem();

	SystemManager::getInstance()->AddSystem(system);

	ModelRendererSystem* renderer_3d = new ModelRendererSystem(&(camera->camera));

	SystemManager::getInstance()->AddSystem(renderer_3d);

	PhysicsSystem* physics_system = new PhysicsSystem();

	physics_system->active = false;

	SystemManager::getInstance()->AddSystem(physics_system);

	CreateButton(GetScreenWidth() / 1.12 - buttonWidth / 2, GetScreenHeight() / 1.15, buttonWidth, buttonHeight, "", "button_play", [physics_system](Actor* actor)
		{
			if(physics_system != nullptr)
				physics_system->active = !physics_system;
		});


}