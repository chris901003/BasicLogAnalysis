#ifndef NET_PACKAGE_TYPE_DATA_H
#define NET_PACKAGE_TYPE_DATA_H

#include <random>

#include "../PackageInfo/package_info_data.h"
#include "../../Distributed/base_distributed.h"

using namespace std;

struct NetPackageTypeData {
    int tag;
    BaseDistributed* distributed;

    NetPackageTypeData(int tag, BaseDistributed* distributed): 
    tag(tag), 
    distributed(distributed) {};

    virtual PackageInfoData* generatePackageInfoData() = 0;
};

#endif