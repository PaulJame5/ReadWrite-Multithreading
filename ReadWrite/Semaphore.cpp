#include "Semaphore.h"

Semaphore::Semaphore(int count)
{
    this->count = count;
}

Semaphore::Semaphore()
{
    count = 0;
}

void Semaphore::notify(int tid) 
{
    std::unique_lock<std::mutex> lock(mtx);
    count++;
    //notify the waiting thread
    cv.notify_one();
}

void Semaphore::wait(int tid) 
{
    std::unique_lock<std::mutex> lock(mtx);
    while (count == 0) 
    {
        //wait on the mutex until notify is called
        cv.wait(lock);
    }
    count--;
}