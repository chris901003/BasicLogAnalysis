#include <random>
#include <stdexcept>

#include "../base_distributed.h"

using namespace std;

class UniformDistributed: BaseDistributed {
    private:
    int range_min, range_max;
    uniform_int_distribution<> dist;
    mt19937 gen;

    public:
    UniformDistributed(int range_min, int range_max):
    range_min(range_min),
    range_max(range_max),
    dist(range_min, range_max),
    gen(mt19937(random_device()())) {
        if (range_max < range_min) {
            throw invalid_argument("Invalid range");
        } else if (range_min < 0) {
            throw invalid_argument("Invalid range");
        }
    };

    int genPacketCount() override { return dist(gen); }
};