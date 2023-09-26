 #include "systems/headers/system.h"
 

 bool System::AddActor(Actor actor){
    if(std::find(actors.begin(), actors.end(), actor) != actors.end()){
                std::cout<<"Error: Tried to add multiple instances of the same actor to the system!\n";
                return false;
            }

    actors.push_back(actor);

    return true;
 }

 bool System::RemoveActor(Actor actor){
        
        auto it = std::find(actors.begin(), actors.end(), actor);

        if(it == actors.end()){
            std::cout<< "Error: Tried to remove instances of the non-existent actor from the system!\n";
            return false;
        }

        actors.erase(it);

        return true;
 }