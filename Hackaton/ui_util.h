#pragma once
#include "position_component.h"
#include "menu_button.h"
#include "actor.h"
#include "system_manager.h"
#include "sprite_component.h"
#include "texture_registry.h"

inline void CreateButton(float x, float y, float width, float height, std::function<void(Actor*)> lambda)
{
    PositionComponent* component = new PositionComponent(Vector3{ x,y,0 }, Vector3{ width, height, 0 });

    MenuButtonComponent* menuButton = new MenuButtonComponent(lambda);

    SpriteComponent* sprite = new SpriteComponent(TextureRegistry::getInstance()->GrabTexture("buton_neapasat"));

    Actor* actor = new Actor();

    actor->AddComponent(component);
    actor->AddComponent(menuButton);
    actor->AddComponent(sprite);

    SystemManager::getInstance()->AddActor(actor);

}