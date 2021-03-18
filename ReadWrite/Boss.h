#pragma once

class Boss
{
public:
	Boss() { health = 150; numberOfReads = 0; numberOfWrites = 0; };
	~Boss() {};

	int getMyHealth() { numberOfReads++;  return health; };
	void decreaseHealth(int decreaseAmount) { health -= decreaseAmount; if (health < 0) { health = 0; } numberOfWrites++; };
	int numberOfReads = 0;
	int numberOfWrites = 0;
private:
	int health;
};