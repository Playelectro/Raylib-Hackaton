#ifndef SYSTEM
#define SYSTEM


#include <vector>
#include <assert.h>
#include <algorithm>
#include "src\engine\actors\headers\actor.h"

class System{
    private:
        std::vector<Actor> actors;
    protected:
        std::vector<const char*> requirements;
    
    public:
        bool active = true;

        std::vector<const char*> GetRequirements(){
            return requirements;
        }

        virtual bool AddActor(Actor actor);

        virtual bool RemoveActor(Actor actor);

        virtual void Update();

};

#endif