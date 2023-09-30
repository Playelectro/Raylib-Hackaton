#include "button_menu_system.h"

void ButtonMenuSystem::doLogic(std::vector<Actor*> actors, int current) {

	Vector2 mousePosition = GetMousePosition();

	PositionComponent* button_poz = actors[current]->GetComponent<PositionComponent>();
	MenuButton* button_wh = actors[current]->GetComponent<MenuButton>();

	Texture2D buton = TextureRegistry::getInstance()->GrabTexture("buton");

	//SetShapesTexture(buton, Rectangle{ 0,0,32,32 });

	//DrawRectangle(button_poz->transform.translation.x, button_poz->transform.translation.y, button_wh->width, button_wh->height, buton);

	DrawTexture(buton, button_poz->transform.translation.x, button_poz->transform.translation.y, Color{ 0,0,0,0 });

	if (IsMouseButtonPressed(0))
	{
		

		Rectangle button_rectangle = { button_poz->transform.translation.x, button_poz->transform.translation.y, button_wh->width, button_wh->height };
		if (CheckCollisionPointRec(mousePosition, button_rectangle))
		{
			std::cout << "Am fost apasat";

		}
	}

}
