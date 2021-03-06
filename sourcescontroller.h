#ifndef SOURCECONTROLLER_H
#define SOURCECONTROLLER_H

#include "source.h"
#include "ostream"
#include <list>
#include <vector>
#include <utility>

// Надо потом отнаследовать init

class StatisticsInfoManager;

class SourcesController {
    friend class StatisticsInfoManager;
public:    
    SourcesController();

    void init(std::vector<std::pair<float, float>> args);
    /**
     * @brief pullBid
     * @return
     *
     * Вытаскивает самый подходящий по времени поток
     */
    Source &pullMinSource();
    float getMinSourceTime();
    Bid pullMinSourceBid();
    void initSources();

    friend std::ostream& operator<< (std::ostream& os, const SourcesController& arg) {
        os << "Sourses:\n";
        for(auto it = arg._sources.begin(); it != arg._sources.end(); ++it) {
            os << (*it).getTime() << "\n";
        }

        return os;
    }


private:
    const std::list<Source> &getSources() const;

private:
    std::list<Source> _sources;    
};



#endif // SOURCECONTROLLER_H
