#include "Enemy.h"

Enemy::Enemy(sf::Texture& texture, sf::Vector2f position, float moveSpeed, float health, float reloadInterval, float damage)
	: moveSpeed(moveSpeed), reloadInterval(reloadInterval), damage(damage), onGoingReload(0.f),
	IDamageAble(&isDestroyed, health, health)
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
}
