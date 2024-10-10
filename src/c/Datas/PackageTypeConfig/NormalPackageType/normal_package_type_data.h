#ifndef NORMAL_PACKAGE_TYPE_DATA_H
#define NORMAL_PACKAGE_TYPE_DATA_H

#include <random>

#include "../net_package_type_data.h"
#include "../../PackageInfo/package_info_data.h"
#include "../../PackageInfo/FilePackageInfo/file_package_info_data.h"

enum PackageType {
    file,
    webview,
    live
};

struct NormalPackageTypeData: NetPackageTypeData {
    private:
    std::uniform_int_distribution<int> packetSizeDist;
    std::mt19937 gen;
    public:
    PackageType type;
    double maxSize, minSize;
    NormalPackageTypeData(
        int tag, 
        double averageArriveRate, 
        PackageType type, 
        double minSize, 
        double maxSize
        ): 
        NetPackageTypeData(tag, averageArriveRate), 
        type(type),
        packetSizeDist(minSize, maxSize), 
        gen(std::mt19937(std::random_device()())),
        maxSize(maxSize), 
        minSize(minSize) {};

    PackageInfoData* generatePackageInfoData() override {
        switch (type) {
            case PackageType::file:
                return new FilePackageInfoData(tag, packetSizeDist(gen));
            case PackageType::webview:
                break;
            case PackageType::live:
                break;
        }
    } 
};

#endif