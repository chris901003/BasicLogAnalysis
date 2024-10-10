#ifndef NORMAL_PACKAGE_TYPE_DATA_H
#define NORMAL_PACKAGE_TYPE_DATA_H

#include <random>

#include "../net_package_type_data.h"
#include "../../PackageInfo/package_info_data.h"
#include "../../../Utilities/RangeGenerator/range_generator.h"
#include "../../../Distributed/base_distributed.h"

enum PackageType {
    file,
    webview,
    live
};

struct NormalPackageTypeData: NetPackageTypeData {
    private:
    RangeGenerator largePacketSizeGen;
    RangeGenerator smallPacketSizeGen;
    double largeFlowRate;

    public:
    PackageType type;
    double maxSize, minSize;
    NormalPackageTypeData(
        int tag, 
        BaseDistributed* baseDistributed, 
        PackageType type, 
        double minSize, 
        double maxSize
        );

    PackageInfoData* generatePackageInfoData() override;
};

#endif