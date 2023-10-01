#include "init_system.h"

void CreateButton(float x, float y, float width, float height, std::function<void(Actor*)> lambda)
{
    PositionComponent* component = new PositionComponent(Vector3{ x,y,0 }, Vector3{width, height, 0});

    MenuButtonComponent* menuButton = new MenuButtonComponent(lambda);

    SpriteComponent* sprite = new SpriteComponent(TextureRegistry::getInstance()->GrabTexture("buton_neapasat"), true);

    Actor* actor = new Actor();

    actor->AddComponent(component);
    actor->AddComponent(menuButton);
    actor->AddComponent(sprite);

    SystemManager::getInstance()->AddActor(actor);

}

void InitUi()
{
    CreateButton(100, 100, 64, 32, [](Actor* a) {std::cout << "I have been clicked"; });
    
    CreateButton(300, 100, 64, 32, [](Actor* a) {std::cout << "Sex"; });

    ButtonMenuSystem* system = new ButtonMenuSystem();

    SystemManager::getInstance()->AddSystem(system);

    SpriteRendererSystem* renderer = new SpriteRendererSystem();

    SystemManager::getInstance()->AddSystem(renderer);
   

}

void InitSystem::doLogic() {


    InitUi();

    // Remove self after implementing begining
    SystemManager::getInstance()->RemoveSystem(this);
}