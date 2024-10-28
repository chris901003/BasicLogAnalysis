#include <iostream>
#include <map>
#include <random>

#include "./Network/network.h"
#include "./Datas/PackageTypeConfig/net_package_type_data.h"
#include "./Datas/PackageTypeConfig/NormalPackageType/normal_package_type_data.h"
#include "./Distributed/Poisson/poisson_distributed.h"
#include "./Distributed/Normal/normal_distributed.h"
#include "./Distributed/Uniform/uniform_distributed.h"
#include "./Distributed/base_distributed.h"

using namespace std;

int main() {
    PoissonDistributed* distributed = new PoissonDistributed(2);
    NormalDistributed* normalDistributed = new NormalDistributed(5, 3);
    UniformDistributed* uniformDistributed = new UniformDistributed(1, 10);
    vector<NetPackageTypeData*> packageTypes;
    packageTypes.push_back(new NormalPackageTypeData(1, (BaseDistributed*)uniformDistributed, PackageType::live, 2000, 2500));
    Network network(packageTypes);
    for (int i = 0; i < 3; i++) {
        vector<NetPackageData*> packages = network.generatePackages();
        cout << "======= Result =======" << endl;
        for (NetPackageData* package: packages) {
            cout << package->id << " " << package->tag << " " << package->packetSize << " " << package->packetCount << endl;
        }
        cout << "======================" << endl;
    }
    return 0;
}