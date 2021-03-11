#include "Writer.h"
#include <iostream>

Writer::Writer(Semaphore* sharedLock, Boss* boss)
{
	this->sharedWriterLock = sharedLock;
	myId = nextId++;
	this->boss = boss;
}

Writer::~Writer()
{
}

void Writer::changeBossHealth() {
	while (true) 
	{
		sharedWriterLock->notify(myId);

		boss->decreaseHealth(10);
		std::cout << "Writer ID: " << myId << ", decreased boss health to: " /*<< boss->getMyHealth()*/  << "\n";

		sharedWriterLock->wait(myId);
		if (boss->getMyHealth() == 0)
		{
			break;
		}
	}
}
int Writer::nextId = 0;

