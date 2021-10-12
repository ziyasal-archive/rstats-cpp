
#include <iostream>
#include "Stats.h"

// truncates,  rounding is challenging especially on tie-breaking rules for rounding to nearest
#define ROUNDF(f, c) (((float)((int)((f) * (c))) / (c)))

Stats::Stats(const int maxResponseTime) {

    this->maxResponseTime = maxResponseTime;

    // could be better, assumes  2 decimal places [.00, .99], truncated
    for (int i = 1; i < this->maxResponseTime; ++i) {
        this->responseTimes[i] = 0;

        for (int j = 1; j < 100; ++j) {
            this->responseTimes[i + (j / 100)] = 0;
        }
    }
}

void Stats::push(float responseTimeInMs) {
    this->responseTimes[ROUNDF(responseTimeInMs, 100)]++;

    this->counter++;
    this->sum += ROUNDF(responseTimeInMs, 100);
}

double Stats::mean() {
    return this->sum / this->counter;
}

float Stats::median() {
    int mid = counter / 2;
    bool isEven = counter % 2 == 0;
    double acc = 0;
    // holds the previous key to calculate the mean to find out the median
    // in case the length of the map is even
    float prevItem;

    for (const auto &kv: this->responseTimes) {
        // std::cout << kv.first << " has value " << kv.second << std::endl;
        acc += kv.second;

        if (acc >= mid && isEven) {
            return (prevItem + kv.first) / 2;
        }

        if (acc >= mid && !isEven) {
            return kv.first;
        }

        prevItem = kv.first;
    }

    return 0;
}
