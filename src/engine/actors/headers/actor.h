#ifndef ACTOR
#define ACTOR

#include <unordered_map>
#include <assert.h>
#include <typeinfo>
#include <iostream>
#include "src\engine\components\headers\component.h"
#include <vector>

class Actor{
    private:
    std::unordered_map<const char*, Component*> components;

    public:
    bool flagged = false;
    int systems = 0;

    void AddComponent(Component*);

    std::vector<const char*> GetComponents();
    
    // Using typename for easy search by passing <> param
    template<typename T>
    T& GetComponent();

    ~Actor(){
        for(auto it = this->components.begin(); it != this->components.end(); it++){
            delete it->second;
        }

        this->components.clear();
    }
};


#endif