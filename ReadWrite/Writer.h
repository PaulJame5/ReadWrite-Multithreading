#pragma once

#include <mutex>
#include <thread>
#include "Globals.h"
#include "Boss.h"
#include "Semaphore.h"

class Writer
{
public:
	Writer(Semaphore* sharedLock, Boss* boss);
	~Writer();

	void changeBossHealth();

	Semaphore* sharedWriterLock;

	int myId = 0;
private:

	static int nextId;
	Boss* boss;
};