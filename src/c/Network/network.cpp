#include <iostream>
#include <random>

#include "network.h"
#include "../Utilities/utilities_string.h"
#include "../Datas/PackageTypeConfig/NormalPackageType/normal_package_type_data.h"

using namespace std;

Network::Network(vector<NetPackageTypeData*> packageTypes) {
    this->packageTypes = packageTypes;
    gen = mt19937(random_device()());
}

vector<NetPackageData*> Network::generatePackages() {
    for (NetPackageTypeData* packageType: packageTypes) {
        int packetCount = packageType->distributed->genPacketCount();
        for (int i = 0; i < packetCount; i++) {
            packageInfoDatas.push_back(packageType->generatePackageInfoData());
        }
    }
    vector<NetPackageData*> packages;
    vector<PackageInfoData*> nxt;
    for (PackageInfoData* packageInfoData: packageInfoDatas) {
        NetPackageData* package = packageInfoData->generatePackage();
        if (package->packetSize > 0) {
            packages.push_back(package);
            nxt.push_back(packageInfoData);
        }
    }
    packageInfoDatas = nxt;
    return packages;
}