#ifndef LIVE_QUALITY_DATA_H
#define LIVE_QUALITY_DATA_H

#include "../package_info_data.h"
#include "../../../Utilities/RangeGenerator/range_generator.h"

enum LiveQuality {
    low,
    medium,
    high
};

struct LiveQualityData {
    private:
    static constexpr float lowQualityRate = 0.1;
    static constexpr float mediumQualityRate = 0.3;
    static constexpr float highQualityRate = 1;

    LiveQuality quality;
    RangeGenerator lowQualityGen;
    RangeGenerator mediumQualityGen;
    RangeGenerator highQualityGen;

    public:
    LiveQualityData(LiveQuality initialQuality);
    void changeToNextQuality();
    int getPacketSize();
};

#endif