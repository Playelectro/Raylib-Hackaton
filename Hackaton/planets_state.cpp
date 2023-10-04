#include "planets_state.h"
void PlanetState::InitState() {
	///BACKGROUND
	Actor* actor;
	actor = new Actor();

	PositionComponent* position;
	position = new PositionComponent(Vector3{ 0, 0, 0 }, Vector3{ (float)GetScreenWidth(),(float)GetScreenHeight(), 0 });

	SpriteComponent* sprite;
	sprite = new SpriteComponent(TextureRegistry::getInstance()->GrabTexture(std::string("cosmos")), 0);

	actor->AddComponent(position);

	actor->AddComponent(sprite);

	SystemManager::getInstance()->AddActor(actor);
	///CAMERA
	Actor* player = new Actor();

	CameraComponent* camera = new CameraComponent({ -40, 2, 0 }, { 0,0,0 }, 90.0f);

	player->AddComponent(camera);

	CameraControlsSystem* camera_control = new CameraControlsSystem();

	SystemManager::getInstance()->AddSystem(camera_control);

	SystemManager::getInstance()->AddActor(player);



	float buttonWidth = 100, buttonHeight = 50;
	CreateButton(GetScreenWidth() / 11 - buttonWidth / 2, GetScreenHeight() / 1.15, buttonWidth, buttonHeight, 30, "Back", "button", [](Actor* actor) {
		ContextState::getInstance()->RegressState();
		ContextState::getInstance()->InitState();
		});

	actor = new Actor();

	position = new PositionComponent(Vector3{ 10, 0, 3 }, Quaternion{ 0.0, 1.0, 0.0, 3 }, Vector3{ 0.1,0.1,0.1 });
	///SYSTEMS
	SpriteRendererSystem* renderer = new SpriteRendererSystem();

	SystemManager::getInstance()->AddSystem(renderer);

	ButtonMenuSystem* system = new ButtonMenuSystem();

	SystemManager::getInstance()->AddSystem(system);

	ModelRendererSystem* renderer_3d = new ModelRendererSystem(&(camera->camera));

	SystemManager::getInstance()->AddSystem(renderer_3d);

	SpinActorSystem* spin_system = new SpinActorSystem;

	SystemManager::getInstance()->AddSystem(spin_system);

	Actor* actor1;
	actor1 = new Actor();

	RotateAroundAxisComponent* spin = new RotateAroundAxisComponent(3);

	ModelComponent* model2 = new ModelComponent(ModelRegistry::getInstance()->GrabModel(0, 2, 60, 60), TextureRegistry::getInstance()->GrabTexture("textura"));

	PositionComponent* position2 = new PositionComponent(Vector3{ 0, 0, 30 }, { 0, 1, 0, 3 }, {2,2,});

	actor1->AddComponent(model2);

	actor1->AddComponent(position2);

	actor1->AddComponent(spin);

	SystemManager::getInstance()->AddActor(actor1);


	Actor* actor2;
	actor2 = new Actor();

	ModelComponent* model3 = new ModelComponent(ModelRegistry::getInstance()->GrabModel(1, 2, 60, 60), TextureRegistry::getInstance()->GrabTexture("textura"));

	PositionComponent* position3 = new PositionComponent(Vector3{ 0, 0, 30 }, { 0, 1, 0, 0 }, { 2,2,2 });

	RotateAroundAxisComponent* spin3 = new RotateAroundAxisComponent(3);

	actor2->AddComponent(model3);

	actor2->AddComponent(position3);

	SystemManager::getInstance()->AddActor(actor2);

	Actor* actor3;
	actor3 = new Actor();

	ModelComponent* model4 = new ModelComponent(ModelRegistry::getInstance()->GrabModel(0, 2, 60, 60), TextureRegistry::getInstance()->GrabTexture("textura"));

	PositionComponent* position4 = new PositionComponent(Vector3{ 0, 0, 30 }, { 0, 1, 0, 0 }, { 2,2,2 });

	RotateAroundAxisComponent* spin4 = new RotateAroundAxisComponent(3);

	actor3->AddComponent(model4);

	actor3->AddComponent(position4);

	SystemManager::getInstance()->AddActor(actor3);


	Actor* actor4;
	actor4 = new Actor();

	ModelComponent* model5 = new ModelComponent(ModelRegistry::getInstance()->GrabModel(1, 2, 60, 60), TextureRegistry::getInstance()->GrabTexture("textura"));

	PositionComponent* position5 = new PositionComponent(Vector3{ 0, 0, 30 }, { 0, 1, 0, 0 }, { 2,2,2 });

	RotateAroundAxisComponent* spin5 = new RotateAroundAxisComponent(3);

	actor4->AddComponent(model5);

	actor4->AddComponent(position5);

	SystemManager::getInstance()->AddActor(actor4);

	Actor* actor5;
	actor5 = new Actor();

	ModelComponent* model6 = new ModelComponent(ModelRegistry::getInstance()->GrabModel(0, 2, 60, 60), TextureRegistry::getInstance()->GrabTexture("textura"));

	PositionComponent* position6 = new PositionComponent(Vector3{ 0, 0, 30 }, { 0, 1, 0, 0 }, { 2,2,2 });

	RotateAroundAxisComponent* spin6 = new RotateAroundAxisComponent(3);

	actor5->AddComponent(model6);

	actor5->AddComponent(position6);

	SystemManager::getInstance()->AddActor(actor5);


	Actor* actor6;
	actor6 = new Actor();

	ModelComponent* model7 = new ModelComponent(ModelRegistry::getInstance()->GrabModel(1, 2, 60, 60), TextureRegistry::getInstance()->GrabTexture("textura"));

	PositionComponent* position7 = new PositionComponent(Vector3{ 0, 0, 30 }, { 0, 1, 0, 0 }, { 2,2,2 });

	RotateAroundAxisComponent* spin7 = new RotateAroundAxisComponent(3);

	actor6->AddComponent(model7);

	actor6->AddComponent(position7);

	SystemManager::getInstance()->AddActor(actor6);

	Actor* actor7;
	actor7 = new Actor();

	ModelComponent* model8 = new ModelComponent(ModelRegistry::getInstance()->GrabModel(1, 2, 60, 60), TextureRegistry::getInstance()->GrabTexture("textura"));

	PositionComponent* position8 = new PositionComponent(Vector3{ 0, 0, 30 }, { 0, 1, 0, 0 }, { 2,2,2 });

	RotateAroundAxisComponent* spin8 = new RotateAroundAxisComponent(3);

	actor7->AddComponent(model8);

	actor7->AddComponent(position8);

	SystemManager::getInstance()->AddActor(actor7);

}
