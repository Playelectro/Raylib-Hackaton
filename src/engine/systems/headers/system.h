#ifndef SYSTEM
#define SYSTEM


#include <vector>
#include <assert.h>
#include <algorithm>
#include "actors/headers/actor.h"

class System{
    private:
        std::vector<Actor&> actors;
    protected:
        std::vector<const char*> requirements;
    
    public:
        bool active = true;

        std::vector<const char*> GetRequirements(){
            return requirements;
        }

        virtual void AddActor(Actor &actor){

            if(std::find(actors.begin(), actors.end(), actor) != actors.end()){
                std::cout<<"Error: Tried to add multiple instances of the same actor to the system!\n";
                return;
            }

            actors.push_back(actor);
        }

        virtual void RemoveActor(Actor& actor){
            
            auto it = std::find(actors.begin(), actors.end(), actor);

            if(it == actors.end()){
                std::cout<< "Error: Tried to remove instances of the non-existent actor from the system!\n";
                return;
            }

            actors.erase(it);
        }

        virtual void Update();

};

#endif