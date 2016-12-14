#ifndef SOURCE_H
#define SOURCE_H

#include "controller.h"
#include "bid.h"

class Source : public Controller {
public:
    Source(float first, float second, int number);

    Bid generateBid();

private:
    float distributionLaw();
private:
    float _first;
    float _second;
    int _number;
};

#endif // SOURCE_H