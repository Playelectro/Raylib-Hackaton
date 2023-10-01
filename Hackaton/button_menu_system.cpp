#include "button_menu_system.h"

void ButtonMenuSystem::doLogic(std::vector<Actor*> actors, int current) {

	Vector2 mousePosition = GetMousePosition();

	PositionComponent* button_poz = actors[current]->GetComponent<PositionComponent>();
	MenuButtonComponent* button_info = actors[current]->GetComponent<MenuButtonComponent>();
	SpriteComponent* sprite = actors[current]->GetComponent<SpriteComponent>();

	Rectangle button_rectangle = { button_poz->transform.translation.x, button_poz->transform.translation.y, button_poz->transform.scale.x, button_poz->transform.scale.y };
	
	if (CheckCollisionPointRec(mousePosition, button_rectangle))
	{
		sprite->texture = TextureRegistry::getInstance()->GrabTexture("buton");
		
		if (IsMouseButtonPressed(0))
		{
			button_info->onClick(actors[current]);
		}

	}
	else 
	{
		sprite->texture = TextureRegistry::getInstance()->GrabTexture("buton_neapasat");
	}
	
}
