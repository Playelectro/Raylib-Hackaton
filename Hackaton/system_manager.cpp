#include "system_manager.h"

SystemManager* SystemManager::instancePtr = NULL;


System* SystemManager::GetSystem(std::string id) {
 

}


void SystemManager::Update(){
    for (auto i = systems.begin(); i != systems.end(); i++) {
        if(i->second->markDeletion)
            RemoveSystem(i->first);
    }

    for(int l =0; l < actors.size(); l++){
        if (actors[l]->markDeletion) {
            RemoveActor(actors[l]);
            continue;
        }
        Actor* a = actors[l];
        
        if(a->flagged){

            for(auto i = systems.begin(); i != systems.end(); i++){
                auto req = i->second->GetRequirements();
                auto comp = a->GetComponents();
            
                for(int j = 0; j < comp.size(); j++){
                    for(int k=0;k<req.size();k++){
                            
                        if(req[k]==comp[j]){
                            req.erase(req.begin()+k);
                            k--;
                        }
                    }
                }

                    if (req.size()==0){
                        a->systems += i->second->AddActor(a);
                    }else
                        a->systems -= i->second->RemoveActor(a);

            }

                a->flagged = false;

                if(a->systems<=0){
                    RemoveActor(a);
                }

        }
    }
    UpdateSystems();
    
}

void SystemManager::CleanSystem() {
    for (auto i = systems.begin(); i != systems.end(); i++) {
        i->second->markDeletion = true;
    }

    for (int i = 0; i < actors.size(); i++) {
        actors[i]->markDeletion = true;
    }
}

SystemManager::~SystemManager() {
    for (auto i = systems.begin(); i != systems.end(); i++) {
        delete i->second;
    }

    for (int i = 0; i < actors.size(); i++) {
        delete actors[i];
    }
}

void SystemManager::AddActor(Actor* actor){

    if (std::find(actors.begin(), actors.end(), actor) != actors.end()){
        std::cout << "Error : Tried to add the same ACTOR twice to the System Manager!\n";
        return;
    }

    actors.push_back(actor);
}


void SystemManager::RemoveActor(Actor* actor) {

    auto it = std::find(actors.begin(), actors.end(), actor);
    if (it == actors.end()){
        std::cout << "Error : Tried to remove a non-existent ACTOR from the System Manager!\n";
        return;
    }

    actors.erase(it);

    for(auto i = systems.begin(); i != systems.end(); i++){
        i->second->RemoveActor(actor);
    }
}

void SystemManager::AddSystem(System* system){
     assert(std::find(systems.begin(), systems.end(), system) == systems.end() && "Error : Tried to add the same SYSTEM twice to the System Manager!");

    systems[typeid(system).name()] = (system);
}


void SystemManager::RemoveSystem(std::string system ) {

    auto it = systems.find(system)->second;
    assert(it == systems.end() && "Error : Tried to remove a non-existent SYSTEM from the System Manager!");
    delete it;
    systems.erase(it);
   
}


void SystemManager::UpdateSystems(){
    for(auto i = systems.begin(); i != systems.end(); i++){
        if (i->second->active)
            i->second->Update();
    }
}