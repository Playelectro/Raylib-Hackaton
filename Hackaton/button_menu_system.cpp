#include "button_menu_system.h"

void ButtonMenuSystem::doLogic(std::vector<Actor*> actors, int current) {

	Vector2 mousePosition = GetMousePosition();

	PositionComponent* button_poz = actors[current]->GetComponent<PositionComponent>();
	MenuButton* button_info = actors[current]->GetComponent<MenuButton>();

	Texture2D buton = TextureRegistry::getInstance()->GrabTexture("buton");
	Texture2D buton_neapasat = TextureRegistry::getInstance()->GrabTexture("buton_neapasat");

	//SetShapesTexture(buton, Rectangle{ 0,0,32,32});

	//DrawRectangle(button_poz->transform.translation.x, button_poz->transform.translation.y, button_wh->width, button_wh->height, Color{ 255,255,255,255 });

	DrawTextureEx(buton, Vector2{ button_poz->transform.translation.x, button_poz->transform.translation.y}, 0, (GetScreenWidth()+ button_info->width)/ (GetScreenHeight() + button_info->height), Color{ 255,255,255,255 });

	if (IsMouseButtonPressed(0))
	{

		Rectangle button_rectangle = { button_poz->transform.translation.x, button_poz->transform.translation.y, button_info->width, button_info->height };
		if (CheckCollisionPointRec(mousePosition, button_rectangle))
		{
			button_info->onClick(actors[current]);
		}
	}

}
