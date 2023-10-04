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

	CameraComponent* camera = new CameraComponent({ -15, 2, 0}, {0,0,0},90.0f);

	player->AddComponent(camera);

	CameraControlsSystem* camera_control = new CameraControlsSystem();

	SystemManager::getInstance()->AddSystem(camera_control);

	SystemManager::getInstance()->AddActor(player);


	// ADD UI BUTTONS
		CreateButton(GetScreenWidth() / 16 - buttonWidthSq / 2, GetScreenHeight() / 25, buttonWidthSq, buttonHeightSq, "", "button_planeta", [](Actor* actor2)
		{

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

	CreateButton(GetScreenWidth() / 1.12 - buttonWidth / 2 + 12, GetScreenHeight() / 1.15, buttonWidth, buttonHeight, "", "button_play", [physics_system](Actor* actor)
		{
				physics_system->active = !physics_system->active;
		});


	// TEST
	Actor* actor1;
	actor1 = new Actor();
	
	PhysicsComponent* phy = new PhysicsComponent(10000, 2, Vector3{ 0, 0, 0 });

	ModelComponent* model2 = new ModelComponent(ModelRegistry::getInstance()->GrabModel(0, 2, 60, 60), TextureRegistry::getInstance()->GrabTexture("textura"));
	
	PositionComponent* position2 = new PositionComponent(Vector3{ 0, 0, 5 });

	actor1->AddComponent(model2);

	actor1->AddComponent(phy);

	actor1->AddComponent(position2);

	SystemManager::getInstance()->AddActor(actor1);


	Actor* actor2;
	actor2 = new Actor();

	PhysicsComponent* phy2 = new PhysicsComponent(10000, 2, Vector3{ 0, 0, 0 });

	ModelComponent* model3 = new ModelComponent(ModelRegistry::getInstance()->GrabModel(1, 2, 60, 60), TextureRegistry::getInstance()->GrabTexture("textura"));

	PositionComponent* position3 = new PositionComponent(Vector3{ 0, 0, -5 });

	actor2->AddComponent(model3);

	actor2->AddComponent(phy2);

	actor2->AddComponent(position3);

	SystemManager::getInstance()->AddActor(actor2);


}
