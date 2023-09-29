#pragma once

#include <vector>
#include <assert.h>
#include <algorithm>
#include "actor.h"

class System{
    private:
        std::vector<Actor*> actors;
    protected:
        std::vector<const char*> requirements;
    
    public:
        bool active = true;

        std::vector<const char*> GetRequirements(){
            return requirements;
        }

        bool AddActor(Actor* actor);

        bool RemoveActor(Actor* actor);

        void Update() {
            for (int i = 0; i < actors.size(); i++) {
                doLogic(actors, i);
            }

            // In case system update without actors
            if (actors.size() == 0) {
                doLogic();
            }
        }

        virtual void doLogic(std::vector<Actor*> actors, int current) {}

        virtual void doLogic() {}

        std::vector<Actor*> getActors() {
            return actors;
        }

        Actor* getActor(int idx) {
            return actors[idx];
        }

};