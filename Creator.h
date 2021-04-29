#pragma once
#include"GameObject.h"
#include<vector>
class Creator
{
public:
	Creator();
	~Creator();
	inline static Creator* instance;
	void Add(GameObject* obj);
	std::vector<GameObject*> gameObjects;
};

