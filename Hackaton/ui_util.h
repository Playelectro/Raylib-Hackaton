#pragma once
#include "position_component.h"
#include "menu_button.h"
#include "actor.h"
#include "system_manager.h"
#include "sprite_component.h"
#include "texture_registry.h"

inline void CreateButton(float x, float y, float width, float height, std::string text, std::string texture, std::function<void(Actor*)> lambda)
{
    PositionComponent* component = new PositionComponent(Vector3{ x,y,0 }, Vector3{ width, height, 0 });

    MenuButtonComponent* menuButton = new MenuButtonComponent(text,texture, width * height / 500,lambda);

    SpriteComponent* sprite = new SpriteComponent(TextureRegistry::getInstance()->GrabTexture(texture.c_str()),2);


    Actor* actor = new Actor();

    actor->AddComponent(component);
    actor->AddComponent(menuButton);
    actor->AddComponent(sprite);

    SystemManager::getInstance()->AddActor(actor);
}

inline void CreateButton(float x, float y, float width, float height, int font_size, std::string text, std::string texture, std::function<void(Actor*)> lambda)
{
    PositionComponent* component = new PositionComponent(Vector3{ x,y,0 }, Vector3{ width, height, 0 });

    MenuButtonComponent* menuButton = new MenuButtonComponent(text, texture, font_size , lambda);

    SpriteComponent* sprite = new SpriteComponent(TextureRegistry::getInstance()->GrabTexture(texture.c_str()), 2);

    Actor* actor = new Actor();

    actor->AddComponent(component);
    actor->AddComponent(menuButton);
    actor->AddComponent(sprite);

    SystemManager::getInstance()->AddActor(actor);
}