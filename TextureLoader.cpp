#include "TextureLoader.h"
#include "Macros.h"

TextureLoader::TextureLoader()
{
	// Jos instansilla ei ole vielä muistiosoitetta, eli sitä ei ole olemassa
	if (instance == nullptr)
	{
		LOG("TextureLoader instanssi luotu!");
		instance = this;
	}
	else {
		LOG("TextureLoader on jo olemassa. Tuhotaan uusi Texture Loader!");
		delete this;
		return;
	}

	backgroundTexture.loadFromFile("Graphics/Backgrounds/blue.png");
	backgroundTexture.setRepeated(true);
	playerTexture.loadFromFile("Graphics/PNG/playerShip3_blue.png");
	playerLaserTexture.loadFromFile("Graphics/PNG/Lasers/laserBlue16.png");
}

TextureLoader::~TextureLoader()
{
	LOG("TextureLoader tuhottu!");
}
