#include <iostream>
#include "Stats.h"

int main() {
    std::unique_ptr<Stats> stats(new Stats(19000));

    stats->push(12);
    stats->push(3.187);
    stats->push(2.82);
    stats->push(2.18);

    std::cout << "Mean: " << stats->mean() << std::endl;
    std::cout << "Median: " << stats->median() << std::endl;

    return 0;
}
