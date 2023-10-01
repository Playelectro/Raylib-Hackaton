#include "button_menu_system.h"

void ButtonMenuSystem::doLogic(std::vector<Actor*> actors, int current) {

	Vector2 mousePosition = GetMousePosition();

	PositionComponent* button_poz = actors[current]->GetComponent<PositionComponent>();
	MenuButtonComponent* button_info = actors[current]->GetComponent<MenuButtonComponent>();
	SpriteComponent* sprite = actors[current]->GetComponent<SpriteComponent>();

	float scale = (3.0f / 4.0f) * ((float)GetRenderWidth() / (float)GetRenderHeight());

	Rectangle button_rectangle = { button_poz->transform.translation.x, button_poz->transform.translation.y, button_poz->transform.scale.x * scale, button_poz->transform.scale.y * scale };
	
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
