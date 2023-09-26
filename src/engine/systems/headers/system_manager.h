#ifndef SYSTEM_MANAGER
#define SYSTEM_MANAGER

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
        static SystemManager* manager;

        void UpdateSystems(); 
        SystemManager();

    public:

        static SystemManager* GetInstance();


        ~SystemManager(){
            delete manager;
        }

        SystemManager(SystemManager &other) = delete;

        void AddActor(Actor*);
        void RemoveActor(Actor*);
        void Update();
        void AddSystem(System*);
        void RemoveSystem(System*);


};


#endif