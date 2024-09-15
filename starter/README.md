# Pybind11 - Starter project
Following throught docs

Step 1: Install Pybind11
pip install "pybind11[global]"

Step 2: Include the headers

```cpp
#include <pybind11/pybind11.h>
namespace py = pybind11;
```

Step 3: Write or Pick some C++ code
```cpp
int add(int i, int j) {
    return i + j;
}
```

Step 4: Write bindings to the code
```cpp

PYBIND11_MODULE(example, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring

    m.def("add", &add, "A function that adds two numbers",
		    py::arg("i"), py::arg("j")
		    );
    m.def("add1", &add, py::arg("i") = 1, py::arg("j") = 2);
    m.def("add2", &add, "i"_a = 1, "j"_a = 2);
    m.attr("the_answer") = 42;
    py::object world = py::cast("World");
    m.attr("what") = world;
}
```

Step 5: Compile

```bash
$ c++ -O3 -Wall -shared -std=c++11 -fPIC $(python3 -m pybind11 --includes) example.cpp -o example$(python3-config --extension-suffix)
# "python3 -m module" is a way to execute module
# python -m pybind11 --includes Include flags for both pybind11 and Python headers.
# python3-config output build options for python C/C++ extensions or embedding 
```

Step 6: Consume

```bash
$ python
Python 3.10.12 (main, Nov 20 2023, 15:14:05) [GCC 11.4.0] on linux
Type "help", "copyright", "credits" or "license" for more information.
>>> import example
>>> example.add(20,22)
42
```
