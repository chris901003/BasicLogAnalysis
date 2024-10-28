#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "../../Distributed/Poisson/poisson_distributed.h"

namespace py = pybind11;

PYBIND11_MODULE(PoissonDistributedTest, m) {
    py::class_<PoissonDistributed>(m, "PoissonDistributed")
        .def(py::init<double>())
        .def("genPacketCount", &PoissonDistributed::genPacketCount);
}