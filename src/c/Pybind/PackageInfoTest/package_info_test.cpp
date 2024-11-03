#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "../../Datas/PackageResponse/net_package_data.h"

#include "../../Datas/PackageInfo/package_info_data.h"
#include "../../Datas/PackageInfo/FilePackageInfo/file_package_info_data.h"
#include "../../Datas/PackageInfo/WebViewPackageInfo/web_view_package_info_data.h"

#include "../../Datas/PackageInfo/LivePackageInfo/live_quality_data.h"
#include "../../Datas/PackageInfo/LivePackageInfo/live_package_info_data.h"

namespace py = pybind11;


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

PYBIND11_MODULE(PackageInfoTest, m) {
    py::class_<NetPackageData>(m, "NetPackageData")
        .def(py::init<std::string, int, int, int>(), py::arg("id"), py::arg("tag"), py::arg("packetCount"), py::arg("packetSize") = 0)
        .def_readwrite("id", &NetPackageData::id)
        .def_readwrite("tag", &NetPackageData::tag)
        .def_readwrite("packetCount", &NetPackageData::packetCount)
        .def_readwrite("packetSize", &NetPackageData::packetSize);
    
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
}
