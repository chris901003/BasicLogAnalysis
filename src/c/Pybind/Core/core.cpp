#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// Distributed Session
#include "../../Distributed/base_distributed.h"
#include "../../Distributed/Poisson/poisson_distributed.h"
#include "../../Distributed/Normal/normal_distributed.h"
#include "../../Distributed/Uniform/uniform_distributed.h"

// Net Package Data Session
#include "../../Datas/PackageResponse/net_package_data.h"

// Package Info Data Session
#include "../../Datas/PackageInfo/package_info_data.h"
#include "../../Datas/PackageInfo/FilePackageInfo/file_package_info_data.h"
#include "../../Datas/PackageInfo/WebViewPackageInfo/web_view_package_info_data.h"

#include "../../Datas/PackageInfo/LivePackageInfo/live_quality_data.h"
#include "../../Datas/PackageInfo/LivePackageInfo/live_package_info_data.h"

// Net Package Type Session
#include "../../Datas/PackageTypeConfig/net_package_type_data.h"
#include "../../Datas/PackageTypeConfig/NormalPackageType/normal_package_type_data.h"

// Network Session
#include "../../Network/network.h"

namespace py = pybind11;

struct PyBaseDistributed: BaseDistributed {
    PyBaseDistributed(): BaseDistributed() {}
    int genPacketCount() override {
        PYBIND11_OVERRIDE_PURE(
            int,        // 返回類型
            BaseDistributed,        // 所屬類別
            genPacketCount          // 函數名稱
        );
    }
};

struct PyPackageInfoData: PackageInfoData {
    PyPackageInfoData(const std::string &name, int a, int b, int c)
        : PackageInfoData(name, a, b, c) {}
    NetPackageData* generatePackage() override {
        PYBIND11_OVERRIDE_PURE(
            NetPackageData*,        // 返回類型
            PackageInfoData,        // 所屬類別
            generatePackage          // 函數名稱
        );
    }
};

struct PyNetPackageTypeData: NetPackageTypeData {
    PyNetPackageTypeData(int tag, BaseDistributed* distributed): NetPackageTypeData(tag, distributed) {}
    PackageInfoData* generatePackageInfoData() override {
        PYBIND11_OVERRIDE_PURE(
            PackageInfoData*,          // 返回類型
            NetPackageTypeData,        // 所屬類別
            generatePackageInfoData    // 函數名稱
        );
    }
};

PYBIND11_MODULE(PoissonNet, m) {
    // Distributed Session
    py::class_<BaseDistributed, PyBaseDistributed, std::shared_ptr<BaseDistributed>>(m, "BaseDistributed")
        .def(py::init<>())
        .def("genPacketCount", &BaseDistributed::genPacketCount);

    py::class_<PoissonDistributed, BaseDistributed, std::shared_ptr<PoissonDistributed>>(m, "PoissonDistributed")
        .def(py::init<double>())
        .def("genPacketCount", &PoissonDistributed::genPacketCount);

    py::class_<NormalDistributed, BaseDistributed, std::shared_ptr<NormalDistributed>>(m, "NormalDistributed")
        .def(py::init<double, double>())
        .def("genPacketCount", &NormalDistributed::genPacketCount);

    py::class_<UniformDistributed, BaseDistributed, std::shared_ptr<UniformDistributed>>(m, "UniformDistributed")
        .def(py::init<double, double>())
        .def("genPacketCount", &UniformDistributed::genPacketCount);

    // Net Package Data Session
    py::class_<NetPackageData>(m, "NetPackageData")
        .def(py::init<std::string, int, int, int>(), py::arg("id"), py::arg("tag"), py::arg("packetCount"), py::arg("packetSize") = 0)
        .def_readwrite("id", &NetPackageData::id)
        .def_readwrite("tag", &NetPackageData::tag)
        .def_readwrite("packetCount", &NetPackageData::packetCount)
        .def_readwrite("packetSize", &NetPackageData::packetSize);
    
    // Package Info Data Session
    py::class_<PackageInfoData, PyPackageInfoData, std::shared_ptr<PackageInfoData>>(m, "PackageInfoData")
        .def(py::init<std::string, int, int, int>())
        .def("generatePackage", &PackageInfoData::generatePackage);
    
    py::class_<FilePackageInfoData, PackageInfoData, std::shared_ptr<FilePackageInfoData>>(m, "FilePackageInfoData")
        .def(py::init<int, int>())
        .def("generatePackage", &FilePackageInfoData::generatePackage);

    py::class_<WebViewPackageInfoData, PackageInfoData, std::shared_ptr<WebViewPackageInfoData>>(m, "WebViewPackageInfoData")
        .def(py::init<int, int>())
        .def("generatePackage", &WebViewPackageInfoData::generatePackage);
    
    py::enum_<LiveQuality>(m, "LiveQuality")
        .value("low", LiveQuality::low)
        .value("medium", LiveQuality::medium)
        .value("high", LiveQuality::high);

    py::class_<LiveQualityData>(m, "LiveQualityData")
        .def(py::init<LiveQuality>())
        .def("changeToNextQuality", &LiveQualityData::changeToNextQuality)
        .def("getPacketSize", &LiveQualityData::getPacketSize);

    py::class_<LivePackageInfoData, PackageInfoData, std::shared_ptr<LivePackageInfoData>>(m, "LivePackageInfoData")
        .def(py::init<int, int, LiveQuality>(), py::arg("tag"), py::arg("leftPacketSize"), py::arg("initialQuality") = LiveQuality::medium)
        .def("generatePackage", &LivePackageInfoData::generatePackage);

    // Net Package Type Session
    py::class_<NetPackageTypeData, PyNetPackageTypeData, std::shared_ptr<NetPackageTypeData>>(m, "NetPackageTypeData")
        .def(py::init<int, BaseDistributed*>())
        .def("generatePackageInfoData", &NetPackageTypeData::generatePackageInfoData);

    py::enum_<PackageType>(m, "PackageType")
        .value("file", PackageType::file)
        .value("webview", PackageType::webview)
        .value("live", PackageType::live)
        .export_values();
    
    py::class_<NormalPackageTypeData, NetPackageTypeData, std::shared_ptr<NormalPackageTypeData>>(m, "NormalPackageTypeData")
        .def(py::init<int, BaseDistributed*, PackageType, double, double>())
        .def("generatePackageInfoData", &NormalPackageTypeData::generatePackageInfoData);

    // Network Session
    py::class_<Network>(m, "Network")
        .def(py::init<std::vector<NetPackageTypeData*>>())
        .def("generatePackages", &Network::generatePackages);
}
