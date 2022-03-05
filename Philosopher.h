//
// Created by Ormir Gjurgjej on 05.03.22.
//

#include "Fork.h"

#ifndef DINING_PHILOSOPHERS_PHILOSOPHER_H
#define DINING_PHILOSOPHERS_PHILOSOPHER_H

class Philosopher {
private:
    int maxThinkingTime;
    int maxEatingTime;
    int index;
    bool shouldFinish;

    void waitAndTake(std::shared_ptr<Fork> fork);
    void runLoop(std::vector<std::shared_ptr<Fork>>);

public:
    Philosopher(const int index, const int thinkingTime, const int eatingTime);

    void run(std::vector<std::shared_ptr<Fork>> forks);
    void finish();
};


#endif //DINING_PHILOSOPHERS_PHILOSOPHER_H
