#include "Player.h"
#include "TextureLoader.h"

using Key = sf::Keyboard;
Player::Player(float moveSpeed, float health)
	: moveSpeed(moveSpeed), health(health), localPosition(0.f, 0.f)
{
	setTexture(TextureLoader::instance->playerTexture);
	// setOrigin asettaa pivot pointin
	setOrigin((sf::Vector2f) getTexture()->getSize() * 0.5f);
}

void Player::Start()
{
}

void Player::Update(sf::View& view, float& deltaTime)
{
	if (Key::isKeyPressed(Key::A) || Key::isKeyPressed(Key::Left))
	{
		localPosition.x -= moveSpeed * deltaTime;
	}
	else if (Key::isKeyPressed(Key::D) || Key::isKeyPressed(Key::Right))
	{
		localPosition.x += moveSpeed * deltaTime;
	}

	if (Key::isKeyPressed(Key::W) || Key::isKeyPressed(Key::Up))
	{
		localPosition.y -= moveSpeed * deltaTime;
	}
	else if (Key::isKeyPressed(Key::S) || Key::isKeyPressed(Key::Down))
	{
		localPosition.y += moveSpeed * deltaTime;
	}

	setPosition(view.getCenter() + localPosition);
}
