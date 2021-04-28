#include<SFML/Graphics.hpp>

int main() {
	// Luodaan ikkuna
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Space Shooter");
	window.setFramerateLimit(120);
	// Luodaan while looppi, joka pyörii niin kauan kuin ikkuna on auki. While loop
	// suoritetaan kerran joka framessa, eli vähän niinkuin Unityn Update() funktio.
	while (window.isOpen())
	{
		window.clear();
		// Tähän väliin kaikki, mitä halutaan piirtää yhden framen aikana 

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
				// Suljetaan ikkuna
				window.close();
			}
		}

	}
	return 0;
}