#pragma once
#include<SFML/Graphics.hpp>
class GameObject : public sf::Sprite
{
public:
	// Periv‰t luokat, kutsuvat aina automaattisesti peritt‰v‰n luokan peruskonstruktoria.
	// Peruskonsturktorilla tarkoitetaan siis konstruktoria, joka ei ota mit‰‰n parametrej‰.
	GameObject() : isDestroyed(false) {};
	// = 0 tarkoittaa ns. abstraktia funktiota, joka tarkoittaa sit‰, ett‰ kyseinen
	// funktio on pakko overridata periviss‰ luokissa
	virtual void Start() = 0;
	// Updatea kutsutaan joka frame.
	virtual void Update(sf::View& view, float& deltaTime) = 0;
	// Pidet‰‰n isDestroyed muuttuja kirjaa siit‰, ett‰ onko gameobject elossa vai kuollut
	bool isDestroyed;
};

