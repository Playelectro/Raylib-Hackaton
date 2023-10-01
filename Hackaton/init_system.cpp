#include "init_system.h"

void InitUi()
{
   ///CreateButton(100, 100, 64, 32, [](Actor* a) {std::cout << "I have been clicked"; });
    
    ///CreateButton(300, 100, 64, 32, [](Actor* a) {std::cout << "Sex"; });

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