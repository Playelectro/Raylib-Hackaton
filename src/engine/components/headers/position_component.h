#ifndef POSITION_COMPONENT
#define POSITION_COMPONENT

#include <raylib.h>
#include "component.h"

class PositionComponent : public Component{
    private:
        Transform transform;
        
    public:
        PositionComponent(Vector3 position, Quaternion rotation, Vector3 scale);
        PositionComponent(Vector3 position, Vector3 scale);
        PositionComponent(Vector3 position, float scale);
        PositionComponent(Vector3 position);
};


#endif 