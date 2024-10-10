#include <random>

#include "./normal_package_type_data.h"
#include "../../PackageInfo/FilePackageInfo/file_package_info_data.h"
#include "../../PackageInfo/WebViewPackageInfo/web_view_package_info_data.h"
#include "../../../Distributed/base_distributed.h"

NormalPackageTypeData::NormalPackageTypeData(
    int tag, 
    BaseDistributed* baseDistributed,
    PackageType type, 
    double minSize, 
    double maxSize
    ): 
    NetPackageTypeData(tag, baseDistributed),
    largePacketSizeGen(max(minSize, maxSize * 0.8), maxSize),
    smallPacketSizeGen(minSize, min(minSize * 1.5, maxSize)),
    type(type),
    maxSize(maxSize), 
    minSize(minSize) {
        switch (type) {
            case PackageType::file:
                largeFlowRate = 0.8;
                break;
            case PackageType::webview:
                largeFlowRate = 0.3;
                break;
            case PackageType::live:
                largeFlowRate = 0.1;
                break;
        }
    };

PackageInfoData* NormalPackageTypeData::generatePackageInfoData() {
    double rate = (double)rand() / RAND_MAX;
    int packetSize;
    if (rate < largeFlowRate) {
        packetSize = largePacketSizeGen.generate();
    } else {
        packetSize = smallPacketSizeGen.generate();
    }

    switch (type) {
        case PackageType::file:
            return new FilePackageInfoData(tag, packetSize);
        case PackageType::webview:
            return new WebViewPackageInfoData(tag, packetSize);
        case PackageType::live:
            break;
    }
}