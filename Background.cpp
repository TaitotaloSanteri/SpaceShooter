#include "Background.h"
#include "TextureLoader.h"

Background::Background()
{
	setTexture(TextureLoader::instance->backgroundTexture);
	setTextureRect(sf::IntRect(0, 0, 1280, 10000));
	setPosition(0.f, -9280.f);
}

void Background::Start()
{
}

void Background::Update(sf::View& view, float& deltaTime)
{
}
