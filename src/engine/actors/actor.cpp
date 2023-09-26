#include "src/engine/actors/headers/actor.h"

void Actor::AddComponent(Component* component){
    const char* component_Id = typeid(component).name()+1;
    
    if(this->components.find(component_Id) != this->components.end()){
        std::cout <<  "Error: Tried to register duplicate component!\n";
        return;
    }

    this->components[component_Id] = component;

    flagged = true;
}

template <typename T>
T& Actor::GetComponent(){
    const char* component_Id = typeid(T).name()+1;

    if(this->components.find(component_Id) == this->components.end()){
        std::cout <<  "Error: Component does not exist on this entity\n";
        return;
    }
    
    return this->components[component_Id];
}

std::vector<const char*> Actor::GetComponents(){
    std::vector<const char*> ret;
    for(auto key : components){
        ret.push_back(key.first);
    }
    return ret;
}