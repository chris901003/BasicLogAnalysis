#ifndef WEB_VIEW_PACKAGE_INFO_DATA_H
#define WEB_VIEW_PACKAGE_INFO_DATA_H

#include "../package_info_data.h"
#include "../../../Utilities/RangeGenerator/range_generator.h"

struct WebViewPackageInfoData: PackageInfoData {
    private:
    static const int largePacketMaxSize = 1500;
    static const int largePacketMinSize = 1000;
    static const int smallPacketMaxSize = 500;
    static const int smallPacketMinSize = 100;

    double largeFlowRate = 0.8;
    RangeGenerator largePacketSizeGen;
    RangeGenerator smallPacketSizeGen;

    public:
    WebViewPackageInfoData(
        int tag,
        int leftPacketSize
        );

    NetPackageData* generatePackage() override;
};

#endif