#include "Writer.h"
#include <iostream>
//
//Writer::Writer(Semaphore* sharedLock, Boss* boss)
//{
//	this->sharedWriterLock = sharedLock;
//	myId = nextId++;
//	this->boss = boss;
//}
Writer::Writer(std::mutex* sharedLock, Boss* boss)
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
		sharedWriterLock->lock();

		boss->decreaseHealth(1);
		std::cout << "Writer ID: " << myId << ", decreased boss health to: " << boss->getMyHealth()  << "\n";
		std::cout << "=========================================" << std::endl;
		sharedWriterLock->unlock();
		if (boss->getMyHealth() == 0)
		{
			break;
		}
	}
}
int Writer::nextId = 0;

