//
// Created by Ormir Gjurgjej on 05.03.22.
//

#ifndef DINING_PHILOSOPHERS_FORK_H
#define DINING_PHILOSOPHERS_FORK_H

class Fork {
private:
    bool isTaken;

public:
    Fork();

    void take();
    bool canTake() const;

    void putBack();
};

#endif //DINING_PHILOSOPHERS_FORK_H
