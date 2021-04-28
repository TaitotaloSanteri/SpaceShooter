#pragma once
#include "GameObject.h"
class Background : public GameObject
{
public:
	Background();
	virtual void Start() override;
	virtual void Update(sf::View& view, float& deltaTime) override;
};

