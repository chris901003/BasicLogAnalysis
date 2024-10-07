#ifndef NET_PACKAGE_DATA_H
#define NET_PACKAGE_DATA_H

#include <string>

using namespace std;

struct NetPackageData {
    string id;
    int tag;
    int packetCount;
    int packetSize;

    NetPackageData(
        string id, 
        int tag, 
        int packetCount, 
        int packetSize = 0
        ): 
        id(id), tag(tag), packetCount(packetCount), packetSize(packetSize) {}
};

#endif