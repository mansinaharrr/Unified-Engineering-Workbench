# Unified Engineering Workbench

A C++17 engineering prototype for 1D thermal FEM, ASCII STL and temperature CSV validation, deterministic serial/parallel thermal batch benchmarking, embedded-device mock adapters, and single-sample backpropagation.

## Build and test (Linux)
```bash
./scripts/build_linux.sh
```
Executable commands:
```bash
./build/uew
./build/uew thermal
./build/uew geometry data/sample_geometry.stl
./build/uew csv data/sample_temperature.csv
./build/uew benchmark 1000 80
./build/uew backprop
./build/uew hardware
```

## Windows build
Use Visual Studio 2022 Build Tools or another CMake-compatible MSVC installation and run `scripts/build_windows.bat` from a Developer Command Prompt. The script builds `dist/bin/uew.exe` and copies frontend/data. It deliberately does not rename a CLI executable to `Launch.exe`; a true integrated GUI launcher still needs to be implemented and verified. Validate on a clean Windows 11 x64 system before submission.

## Modules
See `docs/architecture.md`, `docs/embedded_interface.md` and `docs/limitations.md`.

## Supported data
- ASCII STL with `vertex x y z` records.
- CSV with exact header `node_id,x_m,y_m,z_m,temperature_C`.
- The bundled temperature CSV is synthetic, not an actual ANSYS export.
- The bundled STL is self-created sample geometry.

## Results
Generated numerical CSV files, plots, benchmark measurements and host metadata are in `results/`. Benchmark values are specific to the machine that ran the included build.

## Tests
CTest runs parser, boundary condition, FEM error, finite-difference gradient, hardware timeout and serial/parallel agreement checks.

## Important status
This deliverable is a working C++ prototype, not a fully completed submission against every requirement. The static frontend is not yet connected to the backend, interactive 3D visualization is not implemented, and native Windows launch validation remains outstanding. See `docs/limitations.md`.
