#ifndef SYSTEM_MANAGER_ECS
#define SYSTEM_MANAGER_ECS

#include "system.h"
#include "src\engine\actors\headers\actor.h"
#include <assert.h>
#include <vector>
#include <iostream>
#include <cstring>
class SystemManager{

    private:
        std::vector<System*> systems;
        std::vector<Actor*> actors;

        void UpdateSystems(); 

    public:
        void AddActor(Actor*);
        void RemoveActor(Actor*);
        void AddSystem(System*);
        void RemoveSystem(System*);

        void Update();

};


#endif