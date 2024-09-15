# Port Scanner - Pybind11
## Code taken from: [AyushBansalCodes's Leetcode](https://leetcode.com/problems/median-of-two-sorted-arrays/solutions/5492177/easy-and-simple-c-approach-binary-search/)

### Removed Outer class and added binding

```c++
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <vector> // To make sure std::vector<int> used as list[int] in python
...
PYBIND11_MODULE(mtsa, m) {

    m.doc() = "mtsa"; // optional module docstring

    m.def("fmsa", &findMedianSortedArrays, "A function median of sorted arrays",
		    py::arg("nums1"), py::arg("nums2")
		    );
}
```
### Compile
```bash
c++ -O3 -Wall -shared -std=c++11 -fPIC $(python3 -m pybind11 --includes) mtsa.cpp -o mtsa$(python3-config --extension-suffix)
```

### consume

```bash
>>> import mtsa
>>> help(mtsa)
Help on module mtsa:

NAME
    mtsa - mtsa

FUNCTIONS
    fmsa(...) method of builtins.PyCapsule instance
        fmsa(nums1: list[int], nums2: list[int]) -> float
        
        A function median of sorted arrays

FILE
    /home/darkcheftar/mallidi/pybind11-projects/median-of-two-sorted-arrays/mtsa.cpython-310-x86_64-linux-gnu.so
>>> mtsa.fmsa([1,2],[3,4])
2.5
```