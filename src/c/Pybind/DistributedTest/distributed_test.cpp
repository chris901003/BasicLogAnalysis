#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "../../Distributed/Poisson/poisson_distributed.h"
#include "../../Distributed/Normal/normal_distributed.h"
#include "../../Distributed/Uniform/uniform_distributed.h"

namespace py = pybind11;

PYBIND11_MODULE(DistributedTest, m) {
    py::class_<PoissonDistributed>(m, "PoissonDistributed")
        .def(py::init<double>())
        .def("genPacketCount", &PoissonDistributed::genPacketCount);
    
    py::class_<NormalDistributed>(m, "NormalDistributed")
        .def(py::init<double, double>())
        .def("genPacketCount", &NormalDistributed::genPacketCount);
    
    py::class_<UniformDistributed>(m, "UniformDistributed")
        .def(py::init<double, double>())
        .def("genPacketCount", &UniformDistributed::genPacketCount);
}
