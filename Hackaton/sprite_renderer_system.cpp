#include "sprite_renderer_system.h"


void SpriteRendererSystem::doLogic(std::vector<Actor*> actors, int current) {
	SpriteComponent* sprite = actors[current]->GetComponent<SpriteComponent>();
	PositionComponent* position = actors[current]->GetComponent<PositionComponent>();

	Texture2D texture = sprite->texture;

	DrawTexturePro(texture, { 0.0f,0.0f,(float)texture.width, (float)texture.height }, { 0.0f,0.0f,position->transform.scale.x, position->transform.scale.y }, Vector2{ -position->transform.translation.x, -position->transform.translation.y }, 0, Color{ 255,255,255,255 });

}