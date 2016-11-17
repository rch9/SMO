#include "controller.h"

Controller::Controller()
{

}

void Controller::putBid(const Bid &bid) {
    _isFree = false;
    _bid = bid;
}

void Controller::popBid() {
    _isFree = true;
}

const bool &Controller::isFree() {
    return _isFree;
}

void Controller::addServiceTime() {
    _time += distributionLaw();
}
