#include <random>

#include "../base_distributed.h"

using namespace std;

class PoissonDistributed: public BaseDistributed {
    private:
    double averageArriveRate;
    poisson_distribution<> poisson_dist;
    mt19937 gen;

    public:
    PoissonDistributed(double averageArriveRate): 
    averageArriveRate(averageArriveRate), 
    poisson_dist(averageArriveRate), 
    gen(mt19937(random_device()())) {};

    int genPacketCount() override { return poisson_dist(gen); }
};