#ifndef SYSTEM_MANAGER
#define SYSTEM_MANAGER

#include "system.h"
#include "actors/headers/actor.h"
#include <assert.h>
#include <vector>
#include <iostream>

class SystemManager{

    private:
        std::vector<System*> systems;
        std::vector<Actor*> actors;
        static SystemManager* manager;

        void UpdateSystems(); 

    protected:
        SystemManager();

    public:

        static SystemManager* GetInstance();

        SystemManager(SystemManager &other) = delete;
        void operator=(const SystemManager &) = delete;

        void AddActor(Actor*);
        void RemoveActor(Actor*);
        void Update();
        void AddSystem(System*);
        void RemoveSystem(System*);


};


#endif