#pragma once

class Boss
{
public:
	Boss() { health = 500000; };
	~Boss() {};

	int getMyHealth() { return health; };
	void decreaseHealth(int decreaseAmount) { health -= decreaseAmount; if (health < 0) { health = 0; } };
private:
	int health;
};