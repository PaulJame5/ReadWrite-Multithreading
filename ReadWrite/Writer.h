#pragma once

#include <mutex>
#include <thread>
#include "Globals.h"
#include "Boss.h"
#include "Semaphore.h"

class Writer
{
public:
	//Writer(Semaphore* sharedLock, Boss* boss);
	Writer(std::mutex* sharedLock, Boss* boss);
	~Writer();

	void changeBossHealth();

	//Semaphore* sharedWriterLock;
	std::mutex* sharedWriterLock;

	int myId = 0;

	bool finished = false;
private:

	static int nextId;

	Boss* boss;
};