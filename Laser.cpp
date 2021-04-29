#include "Laser.h"
#include "Creator.h"
#include "Macros.h"
// Konstruktorin : jälkeen tulevat komennot ovat ns. member initializers
Laser::Laser(sf::Texture& texture, sf::Vector2f position, float moveSpeed, float damage, sf::Vector2f direction)
	: moveSpeed(moveSpeed), damage(damage), direction(direction), maxLifeTime(2.5f), currentLifeTime(0.f)
{
	setTexture(texture);
	setPosition(position);
}

Laser::~Laser()
{
	LOG("Laser tuhottu!");
}

void Laser::Start()
{
}

void Laser::Update(sf::View& view, float& deltaTime)
{
	move(direction * moveSpeed * deltaTime);
	currentLifeTime += deltaTime;
	if (currentLifeTime >= maxLifeTime)
	{
		isDestroyed = true;
	}
	
}
