#ifndef LIVE_PACKAGE_INFO_DATA_H
#define LIVE_PACKAGE_INFO_DATA_H

#include "../package_info_data.h"
#include "../../../Utilities/RangeGenerator/range_generator.h"
#include "./live_quality_data.h"

struct LivePackageInfoData: PackageInfoData {
    private:
    LiveQualityData qualityData;

    public:
    LivePackageInfoData(
        int tag,
        int leftPacketSize,
        LiveQuality initialQuality
        );
    NetPackageData* generatePackage() override;
};

#endif