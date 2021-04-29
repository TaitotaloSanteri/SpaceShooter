#pragma once
#include"Player.h"
class GameManager
{
public:
	GameManager();
	Player* player;
	inline static GameManager* instance;
};

