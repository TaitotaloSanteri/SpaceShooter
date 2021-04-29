#include<SFML/Graphics.hpp>
#include<vector>
#include"TextureLoader.h"
#include"Background.h"
#include"Player.h"
#include"Macros.h"
#include"Enemy.h"
#include"Creator.h"

void InitializeGameObjects(std::vector<GameObject*>& gameObjects)
{
	gameObjects.emplace_back(new Background());
	gameObjects.emplace_back(new Player(350.f, 100.f));
	gameObjects.emplace_back(new Enemy(TextureLoader::instance->ufoRedTexture, 
									   sf::Vector2f(640.f, -500.f), 50.f, 10.f, 1.f, 5.f));
	gameObjects.emplace_back(new Enemy(TextureLoader::instance->ufoYellowTexture,
		sf::Vector2f(140.f, -950.f), 90.f, 10.f, 1.f, 5.f));
	gameObjects.emplace_back(new Enemy(TextureLoader::instance->ufoGreenTexture,
		sf::Vector2f(1000.f, -750.f), 32.f, 10.f, 1.f, 5.f));
}
void UpdateGameObjects(std::vector<GameObject*>& gameObjects,
	sf::RenderWindow& window,
	sf::View& view,
	float& deltaTime)
{
	// it = iterator
	for (auto it = gameObjects.begin(); it != gameObjects.end();)
	{
		// (*it) ottaa iteraattorin tyypin, joka on meidän tapauksessa GameObject*
		(*it)->Update(view, deltaTime);
		// *(*it) muuttaa sen ensiksi GameObject* tyyppiseksi, josta sitten sulkujen ulkopuolella
		// olevalla * muutetaan se GameObject tyyppiseksi.
		window.draw(*(*it));
		// Tarkistaan if -lauseella, jos kyseinen GameObject on tuhottu (isDestroyed)
		
		// Jos se on tuhottu, deletoidaan (koska se on heap -muistissa), sekä poistetaan
		// se gameObjects vectorista (gameObject.erase(it)), ja asetetaan iteraattorin it
		// arvo manuaalisesti.
		
		// Jos sitä ei ole tuhottu, niin kasvatetaan iteraattorin arvoa yhdellä normaalisti
		// ++it

		// HUOM! Delete ennen erasea!!!
		if ((*it)->isDestroyed)
		{
			delete (*it);
			it = gameObjects.erase(it);
			continue;
		}
		++it;
	}
}

int main() {
	int numero = 10;
	int* numeroPointteri = &numero;
	LOG(numeroPointteri);
	LOG(*numeroPointteri);
	// Luodaan ikkuna. Luodaan _aina_ ensimmäisenä.
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Space Shooter");
	window.setFramerateLimit(120);

	// Luodaan view, joka käytännössä tarkoittaa kameraa. Asetetaan so koko ikkunan kooksi.
	sf::View view(sf::FloatRect(0.f, 0.f, 1280.f, 720.f));
	window.setView(view);

	// Deltaclock luodaan sitä varten, että voidaan yllä deltaTimea.
	sf::Clock deltaClock;

	// Luodaan TextureLoader, heap -muistiin. Kaikki objektit jotka luodaa new avainsanalla
	// PITÄÄ MUISTAA POISTAA (DELETE) ENNEN KUIN NE POISTUU KÄYTÖSTÄ.
	TextureLoader* textureLoader = new TextureLoader();
	// Luodaan Creator, heap -muistiin. Kaikki objektit jotka luodaa new avainsanalla
	// PITÄÄ MUISTAA POISTAA (DELETE) ENNEN KUIN NE POISTUU KÄYTÖSTÄ.
	Creator* creator = new Creator();
	
	// Luodaan Vektori pitämään kaikki pelissä olevat gameobjektit sisällään.
	std::vector<GameObject*> gameObjects;
	InitializeGameObjects(gameObjects);
	
	// Luodaan while looppi, joka pyörii niin kauan kuin ikkuna on auki. While loop
	// suoritetaan kerran joka framessa, eli vähän niinkuin Unityn Update() funktio
	while (window.isOpen())
	{
		// Deltatime muuttujaan lasketaan framejen välillä kulunut aika
		float deltaTime = deltaClock.restart().asMicroseconds() * 0.000001f;
		// Joka framen aluksi ikkunasta poistetaan kaikki grafiikka.
		window.clear();
		// Liikutetaan viewiä joka frame ylöspäin. Näin saadaan tasainen scrollaus aikaan.
		view.move(0.f, -75.f * deltaTime);
		// View pitää myös päivittää ikkunaan joka frame.
		window.setView(view);

		// Tähän väliin kaikki, mitä halutaan piirtää yhden framen aikana 
		// **************************************************************
		UpdateGameObjects(gameObjects, window, view, deltaTime);
		UpdateGameObjects(Creator::instance->gameObjects, window, view, deltaTime);
		// **************************************************************
		// Tähän väliin kaikki, mitä halutaan piirtää yhden framen aikana 
		
		// Kutsutaan window.display, että kaikki piirretty grafiikka näytetään.
		window.display();

		// Luodaan sf:Event tyyppinen muuttuja, tarkistamaan jos käyttäjä painaa jotain
		// ikkunan nappuloista esim. sulku, minimointi jne.
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Jos käyttäjä painaa ikkunan ruksia
			if (event.type == sf::Event::Closed)
			{
				// Tuhotaan kaikki gameobjekti, koska ne on luotu NEW avainsanalla (eli heap -muistissa).
				for (GameObject* gameObject : gameObjects)
				{
					delete gameObject;
				}
				// Tuhotaan textureLoader, koska sekin on luotu NEW avainsanalla.
				delete textureLoader;
				delete creator;
				// Suljetaan ikkuna
				window.close();
			}
		}

	}
	return 0;
}