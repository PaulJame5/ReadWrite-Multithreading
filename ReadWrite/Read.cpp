#include "Read.h"
#include <iostream>
//
//Read::Read(Semaphore* readLock, Semaphore* readWriteLock, Boss* boss)
//{
//	this->readLock = readLock;
//	this->readWriteLock = readWriteLock;
//	myId = nextId;
//	this->boss = boss;
//}

Read::Read(std::mutex* readLock, std::mutex* readWriteLock, Boss* boss)
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
		readLock->lock();
		readCount++;
		if (readCount == 1)
		{
			readWriteLock->lock();
		}std::cout << "Read ID: " << myId << " here with " << readCount << " readers." << std::endl;
		readLock->unlock();// allow more readers
		std::cout << "Read ID: " << myId << ", read boss health: " << boss->getMyHealth() << "\n";
		readLock->lock();
		readCount--;
		if (readCount == 0)
		{
			readWriteLock->unlock();
		}
		readLock->unlock();

		if (boss->getMyHealth() == 0)
		{
			break;
		}
	}
}
int Read::nextId = 0;
int Read::readCount = 0;

