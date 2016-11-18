#include "buffer.h"
#include "devicescontroller.h"

using namespace std;

Buffer::Buffer(int maxSize):
    _maxSize(maxSize) {
}

void Buffer::putBid(const Bid &bid) {
    if (_bids.size() == _maxSize) {
        _bids.pop_back();
    }

    _bids.push_back(bid);
}

Bid Buffer::popBid() {
    auto buf = _bids.begin();
    for(auto it = _bids.begin(); it != _bids.end(); ++it) {
        if (it->getSource() < buf->getSource()) {
            buf = it;
        }
    }
    auto bid = *buf;
    _bids.erase(buf);

    return bid;
}

unsigned Buffer::size() {
    return _bids.size();
}