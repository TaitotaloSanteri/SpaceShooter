#include "GameManager.h"

GameManager::GameManager() :
	player(nullptr)
{
	// Jos instansilla ei ole vielä muistiosoitetta, eli sitä ei ole olemassa
	if (instance == nullptr)
	{
		instance = this;
	}
	else {
		delete this;
		return;
	}
}
