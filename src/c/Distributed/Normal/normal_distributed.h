#include <random>
#include <algorithm>

#include "../base_distributed.h"

using namespace std;

class NormalDistributed: public BaseDistributed {
    private:
    double mean;
    double stddev;
    normal_distribution<> normal_dist;
    mt19937 gen;

    public:
    NormalDistributed(double mean, double stddev):
    mean(mean),
    stddev(stddev),
    normal_dist(mean, stddev),
    gen(mt19937(random_device()())) {};

    int genPacketCount() override { return max(0, (int)normal_dist(gen)); }
};