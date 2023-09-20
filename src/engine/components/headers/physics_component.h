#ifndef PHYSICS_COMPONENT
#define PHYSICS_COMPONENT

#include <raylib.h>
#include "position_component.h"

class PhysicsComponent : public Component{
    private:
        float mass, radius;
        
    public:
        PhysicsComponent(float mass, float radius);
};


#endif 