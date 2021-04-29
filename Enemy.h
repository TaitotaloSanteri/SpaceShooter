#pragma once
#include "GameObject.h"
#include "IDamageAble.h"
class Enemy : public GameObject, IDamageAble 
{
public:
	Enemy(sf::Texture& texture, sf::Vector2f position, float moveSpeed, float health, float reloadInterval, float damage);
	virtual void Start() override;
	virtual void Update(sf::View& view, float& deltaTime) override;
private:
	float moveSpeed, onGoingReload, reloadInterval, damage;
};

