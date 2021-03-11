#pragma once
#include <mutex>
#include <condition_variable>
#include <iostream>

class Semaphore {
public:
    Semaphore(int count);
    Semaphore();

    void notify(int tid);
    void wait(int tid);
private:
    std::mutex mtx;
    std::condition_variable cv;
    int count = 0;
};