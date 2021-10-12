//
// Created by Ziya Sarikaya on 10/1/21.
//

#ifndef RSTATS_CXX_STATS_H
#define RSTATS_CXX_STATS_H

#include <map>

class Stats {
private:
    int maxResponseTime;
    std::map<float, int> responseTimes;
    int counter;
    double sum;

public:
    explicit Stats(int maxResponseTime);

    void push(float responseTimeInMs);

    double mean();

    float median();
};


#endif //RSTATS_CXX_STATS_H
