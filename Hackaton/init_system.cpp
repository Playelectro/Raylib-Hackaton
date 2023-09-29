#include "init_system.h"
#include "position_component.h"
#include "print_system.h"
#include "system_manager.h"

void SpawnTest() {
    Actor* actor = new Actor();

    PositionComponent* component = new PositionComponent(Vector3{ 0,0,0 });

    actor->AddComponent(component);

    PrintSystem* system = new PrintSystem();

    SystemManager::getInstance()->AddSystem(system);

    SystemManager::getInstance()->AddActor(actor);
}

void InitSystem::doLogic() {

    SpawnTest();

    // Remove self after implementing begining
    SystemManager::getInstance()->RemoveSystem(this);
}