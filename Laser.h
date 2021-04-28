#pragma once
#include "GameObject.h"
class Laser : public GameObject
{
public:
	Laser(sf::Texture& texture, float moveSpeed, float damage, sf::Vector2f direction);
	virtual void Start() override;
	virtual void Update(sf::View& view, float& deltaTime) override;
private:
	float moveSpeed, damage;
	sf::Vector2f direction;
};

