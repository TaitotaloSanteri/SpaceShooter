#include "IDamageAble.h"

void IDamageAble::TakeDamage(float damage)
{
	health -= damage;
	if (health <= 0.f)
	{
		*_isDestroyed = true;
	}
}
