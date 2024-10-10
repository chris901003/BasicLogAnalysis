#ifndef PACKAGE_INFO_DATA_H
#define PACKAGE_INFO_DATA_H

#include <string>

#include "../PackageResponse/net_package_data.h"

struct PackageInfoData {
    std::string id;
    int tag;
    int leftPacketSize;
    int packetCount;

    PackageInfoData(
        std::string id, 
        int tag, 
        int leftPacketSize, 
        int packetCount
        ): 
        id(id), tag(tag), leftPacketSize(leftPacketSize), packetCount(packetCount) {}
    
    virtual ~PackageInfoData() = default;
    virtual NetPackageData* generatePackage() = 0;
};

#endif