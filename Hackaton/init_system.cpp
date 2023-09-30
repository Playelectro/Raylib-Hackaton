#include "init_system.h"


void InitUi()
{
    PositionComponent* component = new PositionComponent(Vector3{ 0,0,0 });

    MenuButton* menuButton = new MenuButton(50, 42);

    Actor* actor = new Actor();

    actor->AddComponent(component);
    actor->AddComponent(menuButton);

    ButtonMenuSystem* system = new ButtonMenuSystem();

    SystemManager::getInstance()->AddSystem(system);
    SystemManager::getInstance()->AddActor(actor);

}

void InitSystem::doLogic() {


    InitUi();

    // Remove self after implementing begining
    SystemManager::getInstance()->RemoveSystem(this);
}