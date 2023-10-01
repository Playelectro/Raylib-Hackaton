#include "sprite_renderer_system.h"


void SpriteRendererSystem::doLogic(std::vector<Actor*> actors, int current) {
	SpriteComponent* sprite = actors[current]->GetComponent<SpriteComponent>();
	PositionComponent* position = actors[current]->GetComponent<PositionComponent>();

	Texture2D texture = sprite->texture;

	float scale = (3.0f / 4.0f) * ((float)GetRenderWidth() / (float)GetRenderHeight());

	DrawTexturePro(texture, { 0.0f,0.0f,(float)texture.width, (float)texture.height }, { 0.0f,0.0f,position->transform.scale.x * scale, position->transform.scale.y * scale}, Vector2{-position->transform.translation.x * scale, -position->transform.translation.y * scale}, 0, Color{255,255,255,255});

}