#include "./live_quality_data.h"

LiveQualityData::LiveQualityData(LiveQuality initialQuality): 
    quality(initialQuality),
    lowQualityGen(100, 200),
    mediumQualityGen(200, 400),
    highQualityGen(400, 800) {}

void LiveQualityData::changeToNextQuality() {
    double rate = (double)rand() / RAND_MAX;
    if (rate < lowQualityRate) {
        quality = LiveQuality::low;
    } else if (rate < mediumQualityRate) {
        quality = LiveQuality::medium;
    } else {
        quality = LiveQuality::high;
    }
}

int LiveQualityData::getPacketSize() {
    switch (quality) {
        case LiveQuality::low:
            return lowQualityGen.generate();
        case LiveQuality::medium:
            return mediumQualityGen.generate();
        case LiveQuality::high:
            return highQualityGen.generate();
    }
    return 0;
}