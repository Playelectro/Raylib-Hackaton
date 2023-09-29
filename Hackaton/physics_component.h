#pragma once

#include <raylib.h>
#include "position_component.h"

class PhysicsComponent : public Component{
        
    public:

        float mass, radius;


        PhysicsComponent(float mass, float radius);
};