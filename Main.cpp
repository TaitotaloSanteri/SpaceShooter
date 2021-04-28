#include<SFML/Graphics.hpp>

int main() {
	// Luodaan ikkuna
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Space Shooter");
	window.setFramerateLimit(120);
	// Luodaan while looppi, joka py�rii niin kauan kuin ikkuna on auki. While loop
	// suoritetaan kerran joka framessa, eli v�h�n niinkuin Unityn Update() funktio.
	while (window.isOpen())
	{
		window.clear();
		// T�h�n v�liin kaikki, mit� halutaan piirt�� yhden framen aikana 

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
				// Suljetaan ikkuna
				window.close();
			}
		}

	}
	return 0;
}