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
std::mutex* readWriteLock = new std::mutex;
std::mutex* readerLock = new std::mutex;

//Semaphore* rwLock = new Semaphore(5);
//Semaphore* rLock = new Semaphore(5);


std::condition_variable cv;


int main() {

	Globals::initialiseDataBuffer();
	std::vector<std::thread*> readerThreads;
	std::vector<std::thread*> writerThreads;
	Boss* boss = new Boss();


	for (int i = 0; i < 5; i++)
	{
		Writer p(readWriteLock, boss);
		Read read(readerLock, readWriteLock, boss);

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
	std::cout << "/********************************************************/ " << std::endl;
	std::cout << "Number of Reads: " << boss->numberOfReads << std::endl;
	std::cout << "Number of Reads: " << boss->numberOfReads << std::endl;
	std::cout << "Number of Reads: " << boss->numberOfReads << std::endl;
	std::cout << "Number of Reads: " << boss->numberOfReads << std::endl;
	std::cout << "Number of Writes: " << boss->numberOfWrites << std::endl;
	std::cout << "Number of Writes: " << boss->numberOfWrites << std::endl;
	std::cout << "Number of Writes: " << boss->numberOfWrites << std::endl;
	std::cout << "Number of Writes: " << boss->numberOfWrites << std::endl;
	std::cout << "/********************************************************/ " << std::endl;
	return 0;
}