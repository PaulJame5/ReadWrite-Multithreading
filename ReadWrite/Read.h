#pragma once

#include <mutex>
#include <thread>
#include "Globals.h"
#include "Boss.h"
#include "Semaphore.h"

class Read
{
public:
	//Read(Semaphore* readLock, Semaphore* readWriteLock, Boss* boss);
	Read(std::mutex* readLock, std::mutex* readWriteLock, Boss* boss);
	~Read();

	void readData(int data, int pos);
	void readBossHealth();
	int myId = 0;

	bool finished = false;
private:
	static int nextId;
	/*Semaphore* readLock;
	Semaphore* readWriteLock;*/
	std::mutex* readLock;
	std::mutex* readWriteLock;

	Boss* boss;
	static int readCount;

};