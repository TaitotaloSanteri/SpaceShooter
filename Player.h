#pragma once
#include "GameObject.h"
#include "IDamageAble.h"
class Player : public GameObject, public IDamageAble
{
public:
	Player(float moveSpeed, float health);
	virtual void Start() override;
	virtual void Update(sf::View& view, float& deltaTime) override;
private:
	float moveSpeed, onGoingReloadTime, reloadInterval;
	sf::Vector2f localPosition, laserOffset1, laserOffset2;
	bool canShoot;
};

