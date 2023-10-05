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

	CameraComponent* camera = new CameraComponent({ -100, 2, -10 }, { 0,0,0 }, 90.0f);

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

	/*Actor* actor0;
	actor0 = new Actor();

	RotateAroundAxisComponent* spin0 = new RotateAroundAxisComponent(3);

	ModelComponent* model0 = new ModelComponent(ModelRegistry::getInstance()->GrabModel(0, 2, 60, 60), TextureRegistry::getInstance()->GrabTexture("textura"));

	PositionComponent* position0 = new PositionComponent(Vector3{ 0, 0, -150 }, { 0, 1, 0, 3 }, { 30, 30, 30 });

	actor0->AddComponent(model0); 

	actor0->AddComponent(position0); 

	actor0->AddComponent(spin0);

	SystemManager::getInstance()->AddActor(actor0);*/
	///MERCUR
	Actor* actor1;
	actor1 = new Actor();

	RotateAroundAxisComponent* spin2 = new RotateAroundAxisComponent(0.0085);

	ModelComponent* model2 = new ModelComponent(ModelRegistry::getInstance()->GrabModel(0, 2, 60, 60), TextureRegistry::getInstance()->GrabTexture("texture_mercur"));

	PositionComponent* position2 = new PositionComponent(Vector3{ 0, 0, -120 }, { 0, 1, 0, 3 }, {0.38,0.38,0.38});

	actor1->AddComponent(model2);

	actor1->AddComponent(position2);

	actor1->AddComponent(spin2);

	SystemManager::getInstance()->AddActor(actor1);

	///VENUS
	Actor* actor2;
	actor2 = new Actor();

	ModelComponent* model3 = new ModelComponent(ModelRegistry::getInstance()->GrabModel(1, 2, 60, 60), TextureRegistry::getInstance()->GrabTexture("texture_venus"));

	PositionComponent* position3 = new PositionComponent(Vector3{ 0, 0, -100 }, { 0, -1, 0, 0 }, { 0.94,0.94,0.94 });

	RotateAroundAxisComponent* spin3 = new RotateAroundAxisComponent(0.002);

	actor2->AddComponent(model3);

	actor2->AddComponent(position3);

	actor2->AddComponent(spin3);

	SystemManager::getInstance()->AddActor(actor2);

	///PAMANT
	Actor* actor3;
	actor3 = new Actor();

	ModelComponent* model4 = new ModelComponent(ModelRegistry::getInstance()->GrabModel(0, 2, 60, 60), TextureRegistry::getInstance()->GrabTexture("texture_pamant"));

	PositionComponent* position4 = new PositionComponent(Vector3{ 0, 0, -80 }, { 0, 1, 0, 0 }, { 1, 1, 1});

	RotateAroundAxisComponent* spin4 = new RotateAroundAxisComponent(0.5);

	actor3->AddComponent(model4);

	actor3->AddComponent(position4);

	actor3->AddComponent(spin4);

	SystemManager::getInstance()->AddActor(actor3);

	///MARTE
	Actor* actor4;
	actor4 = new Actor();

	ModelComponent* model5 = new ModelComponent(ModelRegistry::getInstance()->GrabModel(1, 2, 60, 60), TextureRegistry::getInstance()->GrabTexture("texture_marte"));

	PositionComponent* position5 = new PositionComponent(Vector3{ 0, 0, -60 }, { 0, 1, 0, 0 }, { 0.53, 0.53, 0.53 });

	RotateAroundAxisComponent* spin5 = new RotateAroundAxisComponent(0.48);

	actor4->AddComponent(model5);

	actor4->AddComponent(position5);

	actor4->AddComponent(spin5);

	SystemManager::getInstance()->AddActor(actor4);

	///JUPITER
	Actor* actor5;
	actor5 = new Actor();

	ModelComponent* model6 = new ModelComponent(ModelRegistry::getInstance()->GrabModel(0, 2, 60, 60), TextureRegistry::getInstance()->GrabTexture("texture_jupiter")); 

	PositionComponent* position6 = new PositionComponent(Vector3{ 0, 0, -20 }, { 0, 1, 0, 0 }, { 10.97,10.97,10.97 }); 

	RotateAroundAxisComponent* spin6 = new RotateAroundAxisComponent(1.2); 

	actor5->AddComponent(model6); 

	actor5->AddComponent(position6);

	actor5->AddComponent(spin6);

	SystemManager::getInstance()->AddActor(actor5);

	///SATURN
	Actor* actor6;
	actor6 = new Actor();

	ModelComponent* model7 = new ModelComponent(ModelRegistry::getInstance()->GrabModel(0, 2, 60, 60), TextureRegistry::getInstance()->GrabTexture("texture_saturn"));

	PositionComponent* position7 = new PositionComponent(Vector3{ 0, 0, 30 }, { 0, 1, 0, 0 }, { 9.14, 9.14, 9.14 });

	RotateAroundAxisComponent* spin7 = new RotateAroundAxisComponent(1.09);

	actor6->AddComponent(model7);

	actor6->AddComponent(position7);

	actor6->AddComponent(spin7);

	SystemManager::getInstance()->AddActor(actor6);

	///URANUS
	Actor* actor7;
	actor7 = new Actor();

	ModelComponent* model8 = new ModelComponent(ModelRegistry::getInstance()->GrabModel(1, 2, 60, 60), TextureRegistry::getInstance()->GrabTexture("texture_uranus"));

	PositionComponent* position8 = new PositionComponent(Vector3{ 0, 0, 80 }, { 0, 0,1, 0 }, { 3.98,3.98,3.98 });

	RotateAroundAxisComponent* spin8 = new RotateAroundAxisComponent(-0.7);

	actor7->AddComponent(model8);

	actor7->AddComponent(position8);

	actor7->AddComponent(spin8);

	SystemManager::getInstance()->AddActor(actor7);

	///NEPTUN
	Actor* actor8;
	actor8 = new Actor();

	ModelComponent* model9 = new ModelComponent(ModelRegistry::getInstance()->GrabModel(1, 2, 60, 60), TextureRegistry::getInstance()->GrabTexture("texture_neptun"));

	PositionComponent* position9 = new PositionComponent(Vector3{ 0, 0, 120 }, { 0, 1, 0, 0 }, { 3.86,3.86,3.86 });

	RotateAroundAxisComponent* spin9 = new RotateAroundAxisComponent(0.75);

	actor8->AddComponent(model9);

	actor8->AddComponent(position9);

	actor8->AddComponent(spin9);

	SystemManager::getInstance()->AddActor(actor8);
	/*
	///mercur
	addCelestialBody(Vector3{0,0,-120}, 0.38, 1, "texture_mercur");
	///venus
	addCelestialBody(Vector3{ 0,0,-100 }, 0.94 , 1, "texture_venus");
	///pamant
	addCelestialBody(Vector3{ 0,0,-80 }, 1 , 3, "texture_earth");
	///marte
	addCelestialBody(Vector3{ 0,0,-60 }, 0.53, 1, "texture_marte");
	///jupiter
	addCelestialBody(Vector3{ 0,0,-20 }, 10.97 , 1, "texture_jupiter");
	///saturn
	addCelestialBody(Vector3{ 0,0,40 }, 9.14 , 1, "texture_saturn");
	///uranus
	addCelestialBody(Vector3{ 0,0,80 }, 3.98 , 1, "texture_uranus");
	///neptun
	addCelestialBody(Vector3{ 0,0,120 }, 3.86 , 1, "texture_neptun");*/
}
