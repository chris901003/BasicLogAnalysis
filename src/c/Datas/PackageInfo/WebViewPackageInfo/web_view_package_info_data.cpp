#include "./web_view_package_info_data.h"
#include "../../../Utilities/utilities_string.h"

WebViewPackageInfoData::WebViewPackageInfoData(
    int tag,
    int leftPacketSize
    ): 
    PackageInfoData(UtilitiesString::genUUID(), tag, leftPacketSize, 0),
    largePacketSizeGen(largePacketMinSize, largePacketMaxSize),
    smallPacketSizeGen(smallPacketMinSize, smallPacketMaxSize) {}

NetPackageData* WebViewPackageInfoData::generatePackage() {
    double rate = (double)rand() / RAND_MAX;
    int packetSize;
    if (rate < largeFlowRate) {
        packetSize = largePacketSizeGen.generate();
    } else {
        packetSize = smallPacketSizeGen.generate();
    }
    if (packetSize > leftPacketSize) {
        packetSize = leftPacketSize;
    }
    leftPacketSize -= packetSize;
    packetCount++;
    largeFlowRate *= 0.1;
    return new NetPackageData(id, tag, packetCount, packetSize);
}