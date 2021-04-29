#include "Creator.h"
#include "Macros.h"
#include <algorithm>
Creator::Creator()
{
	if (instance == nullptr)
	{
		LOG("Creator instanssi luotu!");
		instance = this;
	}
	else {
		LOG("Creator on jo olemassa. Tuhotaan uusi Creator!");
		delete this;
		return;
	}
}

Creator::~Creator()
{
	LOG("Creator tuhottu!");
	for (GameObject* obj : gameObjects)
	{
		delete obj;
	}
	gameObjects.clear();
}

void Creator::Add(GameObject* obj)
{
	gameObjects.emplace_back(obj);
}
