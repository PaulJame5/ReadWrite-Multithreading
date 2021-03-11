#include "Read.h"
#include <iostream>

Read::Read(Semaphore* readLock, Semaphore* readWriteLock, Boss* boss)
{
	this->readLock = readLock;
	this->readWriteLock = readWriteLock;
	myId = nextId;
	this->boss = boss;
}

Read::~Read()
{
	// Kill Me
}

void Read::readData(int data, int pos) 
{
	std::cout << "Reader ID: " << myId << ", reading boss health: " << data << " at buffer pos: " << pos << "\n";
}

// consumer thread function
void Read::readBossHealth() {

	while (true)
	{
		readLock->notify(myId);
		readCount++;
		if (readCount == 1)
		{
			readWriteLock->notify(myId);
		}
		readLock->wait(myId);// allow more readers
		std::cout << "Read ID: " << myId << ", read boss health: " << boss->getMyHealth() << "\n";
		readLock->notify(myId);
		readCount--;
		if (readCount == 0)
		{
			readWriteLock->wait(myId);
		}
		readLock->wait(myId);

		if (boss->getMyHealth() == 0)
		{
			break;
		}
	}
}
int Read::nextId = 0;
int Read::readCount = 0;

