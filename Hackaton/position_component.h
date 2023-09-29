#pragma once

#include <raylib.h>
#include "component.h"

class PositionComponent : public Component{
        
    public:
        Transform transform;

        PositionComponent(Vector3 position, Quaternion rotation, Vector3 scale);
        PositionComponent(Vector3 position, Vector3 scale);
        PositionComponent(Vector3 position, float scale);
        PositionComponent(Vector3 position);
};
