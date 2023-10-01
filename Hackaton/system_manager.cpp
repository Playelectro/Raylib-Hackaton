#include "system_manager.h"

SystemManager* SystemManager::instancePtr = NULL;

void SystemManager::Update(){
            for(int l =0; l < actors.size(); l++){
                 Actor* a = actors[l];
        
            if(a->flagged){

                for(int i =0; i < systems.size(); i++){
                    auto req = systems[i]->GetRequirements();
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
                        a->systems += systems[i]->AddActor(a);
                    }else
                        a->systems -= systems[i]->RemoveActor(a);

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
    for (int i = 0; i < systems.size(); i++) {
        RemoveSystem(systems[i]);
    }

    for (int i = 0; i < actors.size(); i++) {
        RemoveActor(actors[i]);
    }
}

SystemManager::~SystemManager() {
    for (int i = 0; i < systems.size(); i++) {
        delete systems[i];
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

    for(int i =0; i < systems.size(); i++){
        systems[i]->RemoveActor(actor);
    }
}

void SystemManager::AddSystem(System* system){
     assert(std::find(systems.begin(), systems.end(), system) == systems.end() && "Error : Tried to add the same SYSTEM twice to the System Manager!");

    systems.push_back(system);
}

void SystemManager::RemoveSystem(System* system) {

    auto it = std::find(systems.begin(), systems.end(), system);
    assert(it != systems.end() && "Error : Tried to remove a non-existent SYSTEM from the System Manager!");

    systems.erase(it);
    delete system;
}


void SystemManager::UpdateSystems(){
    for(int i =0; i < systems.size(); i++){
        if (systems[i]->active)
            systems[i]->Update();
    }
}