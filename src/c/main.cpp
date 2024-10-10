#include <iostream>
#include <map>

#include "./Poisson/poisson_net.h"
#include "./Datas/PackageTypeConfig/net_package_type_data.h"
#include "./Datas/PackageTypeConfig/NormalPackageType/normal_package_type_data.h"

using namespace std;

int main() {
    vector<NetPackageTypeData*> packageTypes;
    packageTypes.push_back(new NormalPackageTypeData(1, 2, PackageType::file, 2000, 2500));
    PoissonNet poissonNet(packageTypes);
    for (int i = 0; i < 3; i++) {
        vector<NetPackageData*> packages = poissonNet.generatePackages();
        cout << "======= Result =======" << endl;
        for (NetPackageData* package: packages) {
            cout << package->id << " " << package->tag << " " << package->packetSize << " " << package->packetCount << endl;
        }
        cout << "======================" << endl;
    }

    return 0;
}