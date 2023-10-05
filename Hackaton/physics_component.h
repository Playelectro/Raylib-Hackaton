#pragma once
#include <raylib.h>
#include "component.h"


enum PlanetType {
    GAS,
    SOLID
};

class PhysicsComponent : public Component{
        
    public:

        float mass, radius, density, volume;
        Vector3 velocity;
        PlanetType type; 

        PhysicsComponent(float mass, float radius, Vector3 velocity, PlanetType type, float density) {
            this->mass = mass;
            this->radius = radius;
            this->velocity = velocity;
            this->density = density;
            this->type = type;
        };
};