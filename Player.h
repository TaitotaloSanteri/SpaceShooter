#pragma once
#include "GameObject.h"
class Player : public GameObject
{
public:
	Player(float moveSpeed, float health);
	virtual void Start() override;
	virtual void Update(sf::View& view, float& deltaTime) override;
private:
	float moveSpeed, health;
	sf::Vector2f localPosition;
};

