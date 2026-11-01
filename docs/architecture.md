\# System Architecture



\## 1. Project Structure



The Unified Engineering Workbench is organized into independent C++ modules supported by a static web dashboard.



\- include/: Public C++ interfaces.

\- src/thermal/: Thermal finite-element solver and analytical comparison.

\- src/geometry/: ASCII STL parsing and nodal CSV validation.

\- src/performance/: Serial and parallel benchmarking.

\- src/hardware/: Simulated embedded device interfaces.

\- src/backpropagation/: Gradient calculation and verification.

\- src/main.cpp: Command-line application entry point.

\- tests/: Automated C++ tests.

\- frontend/: HTML, CSS and JavaScript dashboard.

\- data/: Sample geometry and synthetic temperature data.

\- results/: Numerical outputs, plots and console logs.

\- docs/: Technical documentation and assessment evidence.



\## 2. Execution Flow



The C++ modules are executed independently through the command-line application located at dist/bin/uew.exe.



The Windows launcher, dist/Launch.exe, opens the local dashboard using the default browser.



\## 3. Module Responsibilities



The thermal module calculates temperature distributions using a one-dimensional finite-element approach.



The geometry module reads ASCII STL files and validates nodal temperature CSV data.



The performance module compares serial and parallel execution using deterministic workloads.



The hardware module simulates MCU, FPGA and JTAG device interactions.



The backpropagation module calculates gradients, updates parameters and verifies gradients using finite differences.



\## 4. Frontend and Backend Relationship



The frontend is a static dashboard prototype. It is not currently connected to the C++ command-line backend. The engineering computations are executed separately through the command-line application.



\## 5. Hardware Simulation



Embedded interfaces are simulated in software. No physical hardware communication or firmware programming is performed.

