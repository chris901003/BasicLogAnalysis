#include <iostream>
#include <map>

#include "./Poisson/poisson_net.h"

using namespace std;

int main() {
    vector<NetPackageTypeData> packageTypes = {
        NetPackageTypeData(1, 10)
    };
    PoissonNet poissonNet = PoissonNet(packageTypes);
    map<int, int> packageCount;
    for (int i = 0; i < 10000; i++) {
        vector<NetPackageData> packages = poissonNet.generatePackages();
        for (NetPackageData package: packages) {
            packageCount[package.packetCount] += 1;
        }
    }

    for (auto [x, y]: packageCount) {
        cout << x << " " << string(y / 100, '*') << endl;
    }

    return 0;
}