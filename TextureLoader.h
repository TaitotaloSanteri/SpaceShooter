#pragma once
#include <SFML/Graphics.hpp>

class TextureLoader
{
public:
	// Konstruktori
	TextureLoader();
	// Destruktori 
	~TextureLoader();
	sf::Texture backgroundTexture, playerTexture, playerLaserTexture;
	// Singleton (pit�� olla pointteri eli *) Inline avainsana tarkoittaa sit�
	// ett� static tyyppisen muuttujan arvoa ei tarvitse heti m��ritt�� vaan sen voi tehd� my�hemmin
	inline static TextureLoader* instance;
private:

};

