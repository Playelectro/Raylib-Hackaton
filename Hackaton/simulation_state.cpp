#include "simulation_state.h"


void SimulationState::InitState() {
	float buttonWidth = 128, buttonHeight = 64;
	float buttonWidthSq = 64, buttonHeightSq = 64;

	// ADD BACKGROUND
	Actor* actor;
	actor = new Actor();

	SpriteComponent* model = new SpriteComponent(TextureRegistry::getInstance()->GrabTexture("cosmos"),0);
	PositionComponent* pos = new PositionComponent({0,0,0}, Vector3{ (float)GetScreenWidth(),(float)GetScreenHeight(), 0 });

	actor->AddComponent(model);
	actor->AddComponent(pos);

	SystemManager::getInstance()->AddActor(actor);
	


	// ADD PLAYER CAMERA
	Actor* player = new Actor();

	CameraComponent* camera = new CameraComponent({ -15, 5, 0}, {0,-10,0},90.0f);

	player->AddComponent(camera);

	CameraControlsSystem* camera_control = new CameraControlsSystem();

	SystemManager::getInstance()->AddSystem(camera_control);

	SystemManager::getInstance()->AddActor(player);


	// ADD UI BUTTONS
	CreateButton(GetScreenWidth() / 11 - buttonWidth / 2, GetScreenHeight() / 1.15, buttonWidth, buttonHeight, 30, "Back", "button", [](Actor* actor) {
		ContextState::getInstance()->RegressState();
		ContextState::getInstance()->InitState();
	});


	// ADD SYSTEMS
	SpriteRendererSystem* renderer = new SpriteRendererSystem();

	SystemManager::getInstance()->AddSystem(renderer);

	ButtonMenuSystem* system = new ButtonMenuSystem();

	SystemManager::getInstance()->AddSystem(system);

	GridSystem* grid = new GridSystem();

	SystemManager::getInstance()->AddSystem(grid);

	ModelRendererSystem* renderer_3d = new ModelRendererSystem(&(camera->camera));

	SystemManager::getInstance()->AddSystem(renderer_3d);

	PhysicsSystem* physics_system = new PhysicsSystem();

	physics_system->active = false;

	SystemManager::getInstance()->AddSystem(physics_system);

	SpawnPlanetsSystem* spawn_planets = new SpawnPlanetsSystem();

	SystemManager::getInstance()->AddSystem(spawn_planets);

	CreateButton(GetScreenWidth() / 16 - buttonWidthSq / 2, GetScreenHeight() / 25, buttonWidthSq, buttonHeightSq, "", "button_planeta", [spawn_planets](Actor* actor2)
		{
			spawn_planets->isSpawning = true;
		});

	CreateButton(GetScreenWidth() / 1.12 - buttonWidth / 2 + 12, GetScreenHeight() / 1.15, buttonWidth, buttonHeight, "", "button_play", [physics_system](Actor* actor)
		{
				physics_system->active = !physics_system->active;
		});


	addCelestialBody({ 0,0,-10 }, { 0,0,0 }, 100, 1, PlanetType::SOLID, 5.50, "textura");
	addCelestialBody({ 0,0,10 }, { 0,0,0 }, 100, 2, PlanetType::GAS, 1.60, "textura");

}
