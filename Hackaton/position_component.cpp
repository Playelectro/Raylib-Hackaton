#include "position_component.h"

PositionComponent::PositionComponent(Vector3 position, Quaternion rotation, Vector3 scale) {
    this->transform.translation = position;
    this->transform.rotation = rotation;
    this->transform.scale = scale;    
}

PositionComponent::PositionComponent(Vector3 position, Vector3 scale){
    this->transform.translation = position;
    this->transform.rotation = Quaternion{0,0,0,0};
    this->transform.scale = scale;  
}

PositionComponent::PositionComponent(Vector3 position, float scale){
    this->transform.translation = position;
    this->transform.rotation = Quaternion{0,0,0,0};
    this->transform.scale = Vector3{scale,scale,scale};  
}

PositionComponent::PositionComponent(Vector3 position) {
    this->transform.translation = position;
    this->transform.rotation = Quaternion{0,0,0,0};
    this->transform.scale = Vector3{1,1,1};
}