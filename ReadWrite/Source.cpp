#include <cstdlib>
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include "Writer.h"
#include "Read.h"
#include "Boss.h"
#include "Semaphore.h"
//
//std::mutex* readWriteLock = new std::mutex;
//std::mutex* readerLock = new std::mutex;

Semaphore* rwLock = new Semaphore();
Semaphore* rLock = new Semaphore();


std::condition_variable cv;


int main() {

	Globals::initialiseDataBuffer();
	std::vector<std::thread*> readerThreads;
	std::vector<std::thread*> writerThreads;
	Boss* boss = new Boss();


	for (int i = 0; i < 5; i++)
	{
		Writer p(rwLock, boss);
		Read read(rLock, rwLock, boss);

		std::thread writerThread(&Writer::changeBossHealth, p);
		std::thread readerThread(&Read::readBossHealth, read);

		// Separates the thread of execution from the thread object, 
		// allowing execution to continue independently.
		writerThread.detach();
		readerThread.detach();

		writerThreads.push_back(&writerThread);
		readerThreads.push_back(&readerThread);
	}
	while (true)
	{
		// Gameplay Loop
		if (boss->getMyHealth() == 0)
		{
			break;
		}
	}
	return 0;
}