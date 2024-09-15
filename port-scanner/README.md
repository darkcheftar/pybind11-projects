# Port Scanner - Pybind11
## Code taken from: [carlgira's gist](https://gist.github.com/carlgira/0d60018facc53a86c2dd743c47bea0c3)

### Removed main and added binding

```c++

PYBIND11_MODULE(port_scanner, m) {
    m.doc() = "scans for all open ports for given ip address"; // optional module docstring

    m.def("is_open", &port_is_open, "A function which checks if a given port is open for given ip address",
		    py::arg("ip"), py::arg("port")
		    );
    m.def("scan_ports", &scanPorts, "A function which checks if ports in given range are open for given ip address",
		    py::arg("ip"), py::arg("start_port"), py::arg("end_port")
		    );
}
```
### Compile
```bash
c++ -O3 -Wall -shared -std=c++11 -fPIC $(python3 -m pybind11 --includes) port-scanner.cpp -o port_scanner$(python3-config --extension-suffix)
```

### consume

```bash
>>> import port_scanner
>>> help(port_scanner) 
Help on module port_scanner:

NAME
    port_scanner - scans for all open ports for given ip address

FUNCTIONS
    is_open(...) method of builtins.PyCapsule instance
        is_open(ip: str, port: int) -> bool
        
        A function which checks if a given port is open for given ip address
    
    scan_ports(...) method of builtins.PyCapsule instance
        scan_ports(ip: str, start_port: int, end_port: int) -> None
        
        A function which checks if ports in given range are open for given ip address

FILE
    /home/darkcheftar/mallidi/pybind11-projects/port-scanner/port_scanner.cpython-310-x86_64-linux-gnu.so
>>> 
>>> ps.is_open('127.0.0.1',8080)
socket 127.0.0.1:8080 connected. It took 0.00028 seconds
True
## Paralelly ran  
## nc -nlvp 8080
# Listening on 0.0.0.0 8080
# Connection received on 127.0.0.1 43454
>>> ps.scan_ports('127.0.0.1',8075,8085)
socket 127.0.0.1:8080 connected. It took 0.00021 seconds
127.0.0.1:8080 is open
## Paralelly ran 
# $ nc -nlvp 8080
# Listening on 0.0.0.0 8080
# Connection received on 127.0.0.1 46070
```