#include "Enemy.h"
#include "Laser.h"
#include "Creator.h"
#include "TextureLoader.h"
#include "GameManager.h"
#include "MathHelper.h"

Enemy::Enemy(sf::Texture& texture, sf::Vector2f position, float moveSpeed, float health, float reloadInterval, float damage)
	: moveSpeed(moveSpeed), reloadInterval(reloadInterval), damage(damage), onGoingReload(0.f),
	IDamageAble(&isDestroyed, health, health), canShoot(true)
{
	setTexture(texture);
	// setOrigin asettaa pivot pointing
	setOrigin((sf::Vector2f)getTexture()->getSize() * 0.5f);
	setPosition(position);
}

void Enemy::Start()
{
}

void Enemy::Update(sf::View& view, float& deltaTime)
{
	float speed = moveSpeed * deltaTime;
	move(0.f, speed);
	rotate(speed);

	if (!canShoot)
	{
		onGoingReload += deltaTime;
		if (onGoingReload >= reloadInterval)
		{
			onGoingReload = 0.f;
			canShoot = true;
		}
	}
	if (canShoot)
	{
		canShoot = false;
		Creator::instance->Add(new Laser(
			TextureLoader::instance->enemyLaserTexture,
			getPosition(),
			400.f,
			5.f,
			MathHelper::Normalize(GameManager::instance->player->getPosition() - getPosition())
		));
	}
	
}
