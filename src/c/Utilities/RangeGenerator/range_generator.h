#ifndef RANGE_GENERATOR_H
#define RANGE_GENERATOR_H

#include <random>

class RangeGenerator {
    private:
    std::uniform_int_distribution<int> dist;
    std::mt19937 gen;
    public:
    RangeGenerator(int min, int max): dist(min, max), gen(std::mt19937(std::random_device()())) {};
    int generate() { return dist(gen); }
};

#endif