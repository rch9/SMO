#ifndef SOURCE_H
#define SOURCE_H

#include "controller.h"
#include "bid.h"

class SourcesController;

class Source : public Controller {
    friend class SourcesController;
public:
    Source(float first, float second, int number);

    Bid generateBid();
    const int &getBidNumber() const;

private:
    float distributionLaw();
private:
//    Bid _bid;
    float _first;
    float _second;    
    int _bidNumber;
};

#endif // SOURCE_H
