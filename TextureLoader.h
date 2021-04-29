#pragma once
#include <SFML/Graphics.hpp>

// T‰m‰ luokka on tekstuurien yll‰pit‰mist‰ varten. N‰in varmistetaan se, ett‰ jokainen tekstuuri
// ladataan muistiin vain kerran.
class TextureLoader
{
public:
	// Konstruktori
	TextureLoader();
	// Destruktori 
	~TextureLoader();
	sf::Texture backgroundTexture, playerTexture, playerLaserTexture,
				ufoBlueTexture, ufoYellowTexture, ufoGreenTexture, ufoRedTexture, enemyLaserTexture;
	// Singleton (pit‰‰ olla pointteri eli *) Inline avainsana tarkoittaa sit‰
	// ett‰ static tyyppisen muuttujan arvoa ei tarvitse heti m‰‰ritt‰‰ vaan sen voi tehd‰ myˆhemmin
	inline static TextureLoader* instance;
private:

};

