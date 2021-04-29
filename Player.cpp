#include "Player.h"
#include "TextureLoader.h"
#include "Creator.h"
#include "Laser.h"

using Key = sf::Keyboard;
Player::Player(float moveSpeed, float health)
	: moveSpeed(moveSpeed), localPosition(0.f, 0.f),
	laserOffset1(-32.5f, -55.f), laserOffset2(20.f, -55.f), canShoot(true),
	onGoingReloadTime(0.f), reloadInterval(0.6f), IDamageAble(&isDestroyed, health, health)
{
	setTexture(TextureLoader::instance->playerTexture);
	// setOrigin asettaa pivot pointing
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

	if (!canShoot)
	{
		onGoingReloadTime += deltaTime;
		if (onGoingReloadTime >= reloadInterval)
		{
			onGoingReloadTime = 0.f;
			canShoot = true;
		}
	}

	// Jos pelaaja haluaa ampua
	if (canShoot && Key::isKeyPressed(Key::Space))
	{
		canShoot = false;
		Creator::instance->Add(new Laser(
			TextureLoader::instance->playerLaserTexture,
			view.getCenter() + localPosition + laserOffset1,
			450.f,
			10.f,
			sf::Vector2f(0.f, -1.f)
		));
		Creator::instance->Add(new Laser(
			TextureLoader::instance->playerLaserTexture,
			view.getCenter() + localPosition + laserOffset2,
			450.f,
			10.f,
			sf::Vector2f(0.f, -1.f)
		));
	}
	setPosition(view.getCenter() + localPosition);
}
