#include<SFML/Graphics.hpp>
#include<vector>
#include"TextureLoader.h"
#include"Background.h"
#include"Player.h"
#include"Macros.h"
#include"Creator.h"

void InitializeGameObjects(std::vector<GameObject*>& gameObjects)
{
	gameObjects.emplace_back(new Background());
	gameObjects.emplace_back(new Player(150.f, 100.f));
}

int main() {
	// Luodaan ikkuna. Luodaan _aina_ ensimmäisenä.
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Space Shooter");
	window.setFramerateLimit(120);

	// Luodaan view, joka käytännössä tarkoittaa kameraa. Asetetaan so koko ikkunan kooksi.
	sf::View view(sf::FloatRect(0.f, 0.f, 1280.f, 720.f));
	window.setView(view);

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
		window.clear();
		// Liikutetaan viewiä joka frame ylöspäin. Näin saadaan tasainen scrollaus aikaan.
		view.move(0.f, -75.f * deltaTime);
		// View pitää myös päivittää ikkunaan
		window.setView(view);

		// Tähän väliin kaikki, mitä halutaan piirtää yhden framen aikana 
		// **************************************************************
		for (GameObject* gameObject : gameObjects) {
			gameObject->Update(view, deltaTime);
			window.draw(*gameObject);
		}
		for (GameObject* creatorObject : Creator::instance->gameObjects) {
			creatorObject->Update(view, deltaTime);
			window.draw(*creatorObject);
		}
		// **************************************************************
		// Tähän väliin kaikki, mitä halutaan piirtää yhden framen aikana 
		
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