#pragma once
#include<SFML/Graphics.hpp>
class GameObject : public sf::Sprite
{
public:
	// = 0 tarkoittaa ns. abstraktia funktiota, joka tarkoittaa sitä, että kyseinen
	// funktio on pakko overridata perivissä luokissa
	virtual void Start() = 0;
	virtual void Update(sf::View& view, float& deltaTime) = 0;
};

