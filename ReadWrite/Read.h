#pragma once

#include <mutex>
#include <thread>
#include "Globals.h"
#include "Boss.h"
#include "Semaphore.h"

class Read
{
public:
	Read(Semaphore* readLock, Semaphore* readWriteLock, Boss* boss);
	~Read();

	void readData(int data, int pos);
	void readBossHealth();
	int myId = 0;

private:
	static int nextId;
	Semaphore* readLock;
	Semaphore* readWriteLock;

	Boss* boss;
	static int readCount;

};