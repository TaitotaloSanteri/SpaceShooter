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
	// Singleton (pitää olla pointteri eli *) Inline avainsana tarkoittaa sitä
	// että static tyyppisen muuttujan arvoa ei tarvitse heti määrittää vaan sen voi tehdä myöhemmin
	inline static TextureLoader* instance;
private:

};

