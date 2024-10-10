#ifndef FILE_PACKAGE_INFO_DATA_H
#define FILE_PACKAGE_INFO_DATA_H

#include <random>

#include "../package_info_data.h"
#include "../../PackageResponse/net_package_data.h"

struct FilePackageInfoData: PackageInfoData {
    private:
    static const int maxPacketSize = 1500;
    static const int minPacketSize = 1000;
    std::uniform_int_distribution<int> packetSizeDist;
    std::mt19937 gen;

    public:
    FilePackageInfoData(
        int tag,
        int leftPacketSize
        );
    
    NetPackageData* generatePackage() override;
};

#endif