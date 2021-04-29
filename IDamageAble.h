#pragma once
class IDamageAble
{
protected:
	IDamageAble(bool* isDestroyed, float health, float maxHealth) 
		: _isDestroyed(isDestroyed), health(health), maxHealth(maxHealth) {};
	float health, maxHealth;
	bool* _isDestroyed;
	void TakeDamage(float damage);
};

