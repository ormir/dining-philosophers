#include <vector>
#include <iostream>
#include <thread>

#include "Philosopher.h"
#include "Fork.h"

using namespace std;

template<typename  T>
void for_each_in(vector<T> elements, void (*completion)(T)) {
    for (auto element: elements)
        completion(element);
}

int main() {
    srand((unsigned) time(NULL));
    int countPhilosophers = 3;
    int thinkingTime = 500;
    int eatingTime = 500;

    vector<Philosopher> philosophers;
    vector<shared_ptr<Fork>> forks;
    vector<thread> threads;

    // init philosophers
    for (int i = 0; i < countPhilosophers; i++) {
        Philosopher philosopher(i, thinkingTime, eatingTime);
        philosophers.push_back(philosopher);
        forks.push_back(shared_ptr<Fork>(new Fork()));
    }

    // run philosophers
    for (auto philosopher : philosophers)
        threads.push_back(thread(&Philosopher::run, &philosopher, forks));

//    cin.get();

    for (auto philosopher: philosophers)
        philosopher.finish();

    for (auto &thread: threads)
        thread.join();

    return EXIT_SUCCESS;
}

