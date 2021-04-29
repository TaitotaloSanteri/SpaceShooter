#pragma once
#include<SFML/Graphics.hpp>
class MathHelper
{
public:
	static sf::Vector2f Normalize(sf::Vector2f source);
	static float Angle(sf::Vector2f source);
};

