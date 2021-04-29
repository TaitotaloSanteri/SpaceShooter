#include "GameManager.h"

GameManager::GameManager() :
	player(nullptr)
{
	// Jos instansilla ei ole viel� muistiosoitetta, eli sit� ei ole olemassa
	if (instance == nullptr)
	{
		instance = this;
	}
	else {
		delete this;
		return;
	}
}
