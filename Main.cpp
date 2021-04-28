#include<SFML/Graphics.hpp>
#include<vector>
#include"TextureLoader.h"
#include"Background.h"
#include"Macros.h"

void InitializeGameObjects(std::vector<GameObject*>& gameObjects)
{
	gameObjects.emplace_back(new Background());
}

int main() {
	// Luodaan ikkuna. Luodaan _aina_ ensimm�isen�.
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Space Shooter");
	window.setFramerateLimit(120);

	// Luodaan view, joka k�yt�nn�ss� tarkoittaa kameraa. Asetetaan so koko ikkunan kooksi.
	sf::View view(sf::FloatRect(0.f, 0.f, 1280.f, 720.f));
	window.setView(view);

	// Luodaan TextureLoader, heap -muistiin. Kaikki objektit jotka luodaa new avainsanalla
	// PIT�� MUISTAA POISTAA (DELETE) ENNEN KUIN NE POISTUU K�YT�ST�.
	TextureLoader* textureLoader = new TextureLoader();

	// Luodaan Vektori pit�m��n kaikki peliss� olevat gameobjektit sis�ll��n.
	std::vector<GameObject*> gameObjects;
	InitializeGameObjects(gameObjects);
	
	// Luodaan while looppi, joka py�rii niin kauan kuin ikkuna on auki. While loop
	// suoritetaan kerran joka framessa, eli v�h�n niinkuin Unityn Update() funktio
	while (window.isOpen())
	{
		float deltaTime = 0.1f;
		window.clear();
	
		// T�h�n v�liin kaikki, mit� halutaan piirt�� yhden framen aikana 
		for (GameObject* gameObject : gameObjects) {
			gameObject->Update(view, deltaTime);
			window.draw(*gameObject);
		}
		// T�h�n v�liin kaikki, mit� halutaan piirt�� yhden framen aikana 
		window.display();

		// Luodaan sf:Event tyyppinen muuttuja, tarkistamaan jos k�ytt�j� painaa jotain
		// ikkunan nappuloista esim. sulku, minimointi jne.
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Jos k�ytt�j� painaa ikkunan ruksia
			if (event.type == sf::Event::Closed)
			{
				// Tuhotaan kaikki gameobjekti, koska ne on luotu NEW avainsanalla (eli heap -muistissa).
				for (GameObject* gameObject : gameObjects)
				{
					delete gameObject;
				}
				// Tuhotaan textureLoader, koska sekin on luotu NEW avainsanalla.
				delete textureLoader;
				// Suljetaan ikkuna
				window.close();
			}
		}

	}
	return 0;
}