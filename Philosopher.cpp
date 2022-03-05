//
// Created by Ormir Gjurgjej on 05.03.22.
//

#include <iostream>
#include <vector>
#include <thread>
#include "Philosopher.h"

using namespace std;

Philosopher::Philosopher(const int index, const int thinkingTime, const int eatingTime) {
    this->index = index;
    maxThinkingTime = thinkingTime;
    maxEatingTime = eatingTime;
    shouldFinish = false;
}

void Philosopher::run(const vector<shared_ptr<Fork>> forks) {
    runLoop(forks);
//    while (true) {
//        runLoop(forks);
//        if (shouldFinish)
//            break;
//    }

    cout << "phil [" << index << "] finished" << endl;
}

void Philosopher::runLoop(const vector<shared_ptr<Fork>> forks) {
    int thinkTime = (rand() % maxThinkingTime) + 1;
    int eatingTime = (rand() % maxEatingTime) + 1;
    int forkLeftIndex = index;
    int forkRightIndex = (index+1) % forks.size();
    shared_ptr<Fork> forkLeft = forks[forkLeftIndex];
    shared_ptr<Fork> forkRight = forks[forkRightIndex];

    cout << "phil [" << index << "] thinking " << thinkTime << "ms" << endl;
    this_thread::sleep_for(chrono::milliseconds(thinkTime));
    cout << "-> phil [" << index << "] finished thinking" << endl;

    waitAndTake(forkLeft);
    cout << "-> phil [" << index << "] took first fork: " << forkLeftIndex << endl;

    waitAndTake(forkRight);
    cout << "-> phil [" << index << "] took second fork: " << forkRightIndex << endl;

    cout << "phil [" << index << "] eating " << eatingTime << "ms" << endl;
    this_thread::sleep_for(chrono::milliseconds(eatingTime));
    cout << "-> phil [" << index << "] is done eating" << endl;

    forkLeft->putBack();
    forkRight->putBack();
}

void Philosopher::waitAndTake(shared_ptr<Fork> fork) {

    if (!fork->canTake()) {
        int waitTime = 50;
        cout << "phil [" << index << "] waiting " << waitTime  << "ms" << endl;
        this_thread::sleep_for(chrono::milliseconds(waitTime));
    }

    fork->take();
}

void Philosopher::finish() {
    cout << "phil [" << index << "] will finish" << endl;
    shouldFinish = true;
}