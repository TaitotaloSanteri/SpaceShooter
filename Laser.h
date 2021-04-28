#pragma once
#include "GameObject.h"
class Laser : public GameObject
{
public:
	Laser(sf::Texture& texture, sf::Vector2f position, float moveSpeed, float damage, sf::Vector2f direction);
	~Laser();
	virtual void Start() override;
	virtual void Update(sf::View& view, float& deltaTime) override;
private:
	// maxLifeTime = kauan halutaan, ett‰ laser el‰‰. currentLifeTime = t‰m‰n hetkinen elinaika
	float moveSpeed, damage, maxLifeTime, currentLifeTime;
	sf::Vector2f direction;
};

