#include "init_system.h"

void CreateButton(float x, float y, float width, float height)
{
    PositionComponent* component = new PositionComponent(Vector3{ x,y,0 });

    MenuButton* menuButton = new MenuButton(width, height);

    Actor* actor = new Actor();

    actor->AddComponent(component);
    actor->AddComponent(menuButton);

    SystemManager::getInstance()->AddActor(actor);

}

void InitUi()
{
    CreateButton(100, 100, 150, 60);

    ButtonMenuSystem* system = new ButtonMenuSystem();

    SystemManager::getInstance()->AddSystem(system);
   

}

void InitSystem::doLogic() {


    InitUi();

    // Remove self after implementing begining
    SystemManager::getInstance()->RemoveSystem(this);
}