#include <iostream>
#include <random>

#include "poisson_net.h"

using namespace std;

PoissonNet::PoissonNet(vector<NetPackageTypeData> packageTypes) {
    this->packageTypes = packageTypes;
    gen = mt19937(random_device()());
}

vector<NetPackageData> PoissonNet::generatePackages() {
    vector<NetPackageData> packages;
    for (NetPackageTypeData packageType: packageTypes) {
        int packetCount = packageType.poisson_dist(gen);
        NetPackageData package = {packageType.tag, packetCount};
        packages.push_back(package);
    }
    return packages;
}