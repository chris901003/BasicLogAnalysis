#include "./file_package_info_data.h"
#include "../../../Utilities/utilities_string.h"

FilePackageInfoData::FilePackageInfoData(
    int tag,
    int leftPacketSize
    ): 
    PackageInfoData(UtilitiesString::genUUID(), tag, leftPacketSize, 0),
    packetSizeDist(minPacketSize, maxPacketSize),
    gen(std::mt19937(std::random_device()())) {}

NetPackageData* FilePackageInfoData::generatePackage() {
    int packetSize = packetSizeDist(gen);
    if (packetSize > leftPacketSize) {
        packetSize = leftPacketSize;
    }
    leftPacketSize -= packetSize;
    packetCount++;
    return new NetPackageData(id, tag, packetCount, packetSize);
}