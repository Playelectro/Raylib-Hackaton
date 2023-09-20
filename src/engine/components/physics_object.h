#ifndef PHYSICS_COMPONENT
#define PHYSICS_COMPONENT

#include <raylib.h>
#include "component.h"

class PhysicsComponent : public Component{
    private:
        float mass, radius;
        Transform transform;
        
    public:
        PhysicsComponent(float mass, float radius, float scale, Vector3 position);
};


#endif 