# Requirement-to-evidence matrix

| Requirement | Evidence | Status |
|---|---|---|
| C++17 backend and CMake | `src/`, `include/`, `CMakeLists.txt` | Complete and built on Linux |
| Thermal FEM N=10,20,40,80 | `src/thermal/thermal.cpp`, `results/thermal_N*.csv` | Implemented and tested |
| Exact solution and midpoint error | `results/thermal_convergence.csv`, `results/thermal_convergence.png` | Implemented and checked |
| ASCII STL parser | `src/geometry/geometry.cpp`, `data/sample_geometry.stl` | Implemented and tested |
| Required nodal CSV validation | `src/geometry/geometry.cpp`, `data/sample_temperature.csv` | Implemented and tested |
| Interactive 3D STL/point-cloud visualization | Not present | Not implemented |
| Serial and parallel batch execution | `src/performance/benchmark.cpp`, `results/benchmark.csv` | Implemented and tested |
| Five repetitions, median, speedup, efficiency | `results/benchmark.csv`, `results/environment.txt` | Measured |
| MCU, FPGA, JTAG mocks and timeout | `src/hardware/hardware.cpp` | Implemented and tested |
| Hand-derived backprop and finite differences | `src/backpropagation/backprop.cpp`, `results/backprop_console.txt` | Implemented and tested |
| Loss plot and CSV | `results/backprop_loss.*` | Implemented |
| Professional dashboard | `frontend/` | Static UI prototype |
| UI-to-C++ integration and live status | Not present | Not implemented |
| Windows standalone Launch.exe | `scripts/build_windows.bat` | Build script only; not built/verified here |
| README, report, evidence, limitations | `README.md`, `docs/`, `results/` | Included |
