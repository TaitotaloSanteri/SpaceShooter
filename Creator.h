#pragma once
#include"GameObject.h"
#include<vector>
#include<list>
class Creator
{
public:
	Creator();
	~Creator();
	inline static Creator* instance;
	void Add(GameObject* obj);
	std::list<GameObject*> gameObjects;
};

