#ifndef NET_PACKAGE_TYPE_DATA_H
#define NET_PACKAGE_TYPE_DATA_H

#include <random>

using namespace std;

struct NetPackageTypeData {
    int tag;
    double averageArriveRate;
    poisson_distribution<> poisson_dist;

    NetPackageTypeData(int tag, double averageArriveRate): tag(tag), averageArriveRate(averageArriveRate) {
        poisson_dist = poisson_distribution<>(averageArriveRate);
    }
};

#endif