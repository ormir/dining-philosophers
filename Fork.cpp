//
// Created by Ormir Gjurgjej on 05.03.22.
//

#include "Fork.h"

Fork::Fork() {
    isTaken = false;
}

bool Fork::canTake() const {
    return !isTaken;
}

void Fork::take() {
    isTaken = true;
}

void Fork::putBack() {
    isTaken = false;
}
