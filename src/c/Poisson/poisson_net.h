#include <iostream>
#include <random>

#include "../Datas/net_package_data.h"
#include "../Datas/net_package_type_data.h"

using namespace std;

class PoissonNet {
    private:
    mt19937 gen;
    vector<NetPackageTypeData> packageTypes;
    public:
    PoissonNet(vector<NetPackageTypeData> packageTypes);
    vector<NetPackageData> generatePackages();
};