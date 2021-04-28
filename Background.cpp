#include "Background.h"
#include "TextureLoader.h"

Background::Background()
{
	setTexture(TextureLoader::instance->backgroundTexture);
	setTextureRect(sf::IntRect(0, 0, 1280, 720));
}

void Background::Start()
{
}

void Background::Update(sf::View& view, float& deltaTime)
{
}
