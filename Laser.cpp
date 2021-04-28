#include "Laser.h"

// Konstruktorin : j�lkeen tulevat komennot ovat ns. member initializers
Laser::Laser(sf::Texture& texture, float moveSpeed, float damage, sf::Vector2f direction)
	: moveSpeed(moveSpeed), damage(damage), direction(direction)
{
	setTexture(texture);
}

void Laser::Start()
{
}

void Laser::Update(sf::View& view, float& deltaTime)
{
	move(direction * moveSpeed * deltaTime);
}
