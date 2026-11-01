# Unified Engineering Workbench

A C++17 engineering prototype covering thermal finite-element analysis, geometry and CSV validation, multicore benchmarking, simulated embedded interfaces, and backpropagation.

## 1. Windows Quick Start

1. Extract the complete submission ZIP.
2. Open the extracted folder.
3. Double-click `dist/Launch.exe`.
4. The local dashboard opens in your default browser.

Keep the `dist/frontend` folder beside `Launch.exe`. No internet connection or administrator privileges are required to open the packaged dashboard.

## 2. Command-Line Application

The C++ executable is available at `dist/bin/uew.exe`.

Run these commands from the extracted project folder:

```powershell
.\dist\bin\uew.exe thermal
.\dist\bin\uew.exe geometry .\dist\data\sample_geometry.stl
.\dist\bin\uew.exe csv .\dist\data\sample_temperature.csv
.\dist\bin\uew.exe benchmark
.\dist\bin\uew.exe backprop
.\dist\bin\uew.exe hardware
```

## 3. Build and Test

**Prerequisites**
- Windows 11 x64
- CMake 3.20 or later
- Visual Studio C++ Build Tools with Windows SDK
- C++17-compatible compiler

Run `scripts/build_windows.bat` from a Visual Studio Developer Command Prompt to configure CMake, build the Release binaries, run CTest and prepare the distribution folder.

For VS Code:
1. Open `config/uew.code-workspace`.
2. Install Microsoft's C/C++ extension.
3. Select `Launch Packaged Workbench` in the Run and Debug panel.
4. Press F5.

## 4. Engineering Modules

- **Thermal FEM:** One-dimensional linear-element finite-element solver with analytical convergence comparison.
- **Geometry:** ASCII STL parsing and bounding-box calculation.
- **CSV:** Validation of the `node_id,x_m,y_m,z_m,temperature_C` schema.
- **Performance:** Serial and parallel deterministic batch benchmarking.
- **Embedded:** Simulated MCU, FPGA and JTAG adapters with telemetry and timeout handling.
- **Backpropagation:** Gradient calculation, parameter updates and finite-difference verification.

## 5. Data and Results

The supplied temperature CSV is synthetic and is not an ANSYS export. The ASCII STL is a sample geometry file.

Numerical outputs, CSV files, plots, benchmark measurements and console logs are available in the `results/` directory.

## 6. Tests

Automated C++ tests are provided in `tests/` and are executed through CTest. See the build instructions above.

## 7. Architecture

- `include/`: C++ interfaces.
- `src/`: C++ module implementations.
- `frontend/`: Static HTML, CSS and JavaScript dashboard.
- `data/`: Sample STL and synthetic temperature CSV.
- `results/`: Numerical results, plots and console logs.
- `tests/`: Automated tests.
- `docs/`: Technical report, architecture, limitations and supporting evidence.
- `config/`: VS Code workspace configuration.

## 8. Known Limitations

The packaged Windows launcher opens the local static dashboard. The dashboard and C++ command-line executable are separate applications; the dashboard is not connected to the C++ backend.

Interactive 3D mesh rendering, rotate, pan, zoom, fit-to-view, temperature point-cloud rendering, colour legend and node inspection are not implemented.

Embedded hardware communication is simulated. No physical hardware programming or communication is performed.

See `docs/limitations.md` and `docs/requirement_matrix.md` for implementation status and limitations.

## Version Control

The complete source repository and development history are available at:

https://github.com/mansinaharrr/Unified-Engineering-Workbench

A readable commit history is included in `docs/commit_log.txt`.