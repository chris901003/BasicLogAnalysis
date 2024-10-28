#include "./live_package_info_data.h"
#include "../../../Utilities/utilities_string.h"

LivePackageInfoData::LivePackageInfoData(
    int tag,
    int leftPacketSize,
    LiveQuality initialQuality
    ): 
    PackageInfoData(UtilitiesString::genUUID(), tag, leftPacketSize, 0),
    qualityData(initialQuality) {}

NetPackageData* LivePackageInfoData::generatePackage() {
    int packetSize = qualityData.getPacketSize();
    if (packetSize > leftPacketSize) {
        packetSize = leftPacketSize;
    }
    leftPacketSize -= packetSize;
    packetCount++;
    qualityData.changeToNextQuality();
    return new NetPackageData(id, tag, packetCount, packetSize);
}