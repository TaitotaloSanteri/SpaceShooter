#include "MathHelper.h"

sf::Vector2f MathHelper::Normalize(sf::Vector2f source)
{
    float length = sqrt((source.x * source.x) + (source.y * source.y));
    if (length != 0)
    {
        return sf::Vector2f(source.x / length, source.y / length);
    }
    else {
        return source;
    }
}

float MathHelper::Angle(sf::Vector2f source)
{
    // 360 / (PI * 2).
    return atan2(source.y, source.x) * 57.29578f + 90.f;
}
