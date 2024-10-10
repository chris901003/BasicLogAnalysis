#ifndef NETWORK_H
#define NETWORK_H

#include <iostream>
#include <random>

#include "../Datas/PackageResponse/net_package_data.h"
#include "../Datas/PackageTypeConfig/net_package_type_data.h"
#include "../Datas/PackageInfo/package_info_data.h"

using namespace std;

class Network {
    private:
    mt19937 gen;
    vector<NetPackageTypeData*> packageTypes;
    vector<PackageInfoData*> packageInfoDatas;

    public:
    Network(vector<NetPackageTypeData*> packageTypes);
    vector<NetPackageData*> generatePackages();
};

#endif