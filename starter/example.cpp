#include <pybind11/pybind11.h>
using namespace pybind11::literals;
namespace py = pybind11;

int add(int i, int j) {
    return i + j;
}

PYBIND11_MODULE(example, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring
    m.def("add", &add, "A function that adds two numbers",
		    py::arg("i"), py::arg("j")
		    );
    m.def("add1", &add, py::arg("i") = 1, py::arg("j") = 2);
    m.def("add2", &add, "i"_a=1, "j"_a=2);
    m.attr("the_answer") = 42;
    py::object world = py::cast("World");
    m.attr("what") = world;
}
