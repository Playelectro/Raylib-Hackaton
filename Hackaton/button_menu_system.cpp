#include "button_menu_system.h"

void ButtonMenuSystem::doLogic(std::vector<Actor*> actors, int current) {

	Vector2 mousePosition = GetMousePosition();

	PositionComponent* button_poz = actors[current]->GetComponent<PositionComponent>();
	MenuButtonComponent* button_info = actors[current]->GetComponent<MenuButtonComponent>();
	SpriteComponent* sprite = actors[current]->GetComponent<SpriteComponent>();


	Rectangle button_rectangle = { button_poz->transform.translation.x, button_poz->transform.translation.y, button_poz->transform.scale.x, button_poz->transform.scale.y };
	

	int size = MeasureText(button_info->text.c_str(), button_info->font_size);

	DrawText(button_info->text.c_str(), button_poz->transform.translation.x + (button_poz->transform.scale.x / 2) - size/2, button_poz->transform.translation.y + (button_poz->transform.scale.y / 4), button_info->font_size, WHITE);
	
	if (CheckCollisionPointRec(mousePosition, button_rectangle))
	{
		std::string aux = button_info->texture;
		sprite->texture = TextureRegistry::getInstance()->GrabTexture(aux.append("_pressed").c_str());
		
		if (IsMouseButtonPressed(0))
		{
			button_info->onClick(actors[current]);
		}
	}
	else 
	{
		sprite->texture = TextureRegistry::getInstance()->GrabTexture(button_info->texture.c_str());
	}
	
}
