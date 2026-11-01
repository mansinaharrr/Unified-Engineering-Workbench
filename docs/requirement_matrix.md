# Requirement-to-Evidence Matrix

| Assessment Requirement | Evidence Location | Status |
|---|---|---|
| C++17 backend and CMake | `src/`, `include/`, `CMakeLists.txt` | Implemented |
| Thermal FEM at N=10, 20, 40 and 80 | `src/thermal/`, `results/thermal_N*.csv` | Implemented and tested |
| Analytical solution and convergence comparison | `results/thermal_convergence.csv`, plots | Evidence included |
| ASCII STL parsing | `src/geometry/`, `data/sample_geometry.stl` | Implemented |
| Nodal CSV validation | `data/sample_temperature.csv` | Implemented |
| Interactive 3D mesh and point-cloud visualization | Not available | Not implemented |
| Serial and parallel benchmarking | `src/performance/`, `results/benchmark.csv` | Implemented |
| Five repetitions, median, speedup and efficiency | `results/benchmark.csv`, `results/environment.txt` | Evidence included |
| MCU, FPGA and JTAG simulation | `src/hardware/`, `results/hardware_console.txt` | Simulated |
| Backpropagation and finite-difference verification | `src/backpropagation/`, `results/backprop_console.txt` | Implemented and tested |
| Backpropagation loss plot | `results/backprop_loss.png` | Included |
| Windows launcher | `dist/Launch.exe` | Included |
| C++ command-line executable | `dist/bin/uew.exe` | Included |
| Frontend and backend integration | Not available | Not implemented |
| Technical report | `docs/Technical_Report.pdf` | Included |
| Handwritten derivation appendix | `docs/Backpropagation_Derivation_Appendix.pdf` | Included |
| AI-use log and ownership statement | `docs/` | Included |
| Git repository bundle | `docs/Workbench_Repository.bundle` | Included |
| Timestamped demo walkthrough or video | To be added | Pending |