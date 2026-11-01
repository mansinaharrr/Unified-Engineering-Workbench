ARCHITECTURE DOCUMENT



1\. PROJECT STRUCTURE



include/uew.hpp

Contains the public C++17 module interfaces.



src/thermal

Implements a one-dimensional linear-element finite element solver and analytical comparison.



src/geometry

Handles ASCII STL geometry parsing, bounding-box calculations and nodal CSV validation.



src/performance

Implements independent-case benchmarking with serial and parallel worker execution.



src/hardware

Provides simulated MCU, FPGA and JTAG adapters with a recoverable timeout mechanism.



src/backpropagation

Implements one-sample gradient calculation, parameter updates, finite-difference verification and training history.



src/main.cpp

Provides the command-line entry point for executing individual modules.



tests

Contains automated integration tests executed through CTest.



frontend

Contains the HTML, CSS and JavaScript files for the engineering dashboard.



data

Contains sample geometry and synthetic temperature data.



results

Contains generated CSV files, plots, benchmark evidence and environment information.





2\. SYSTEM DESIGN



The C++ core is organized into independent modules. Each module performs a specific engineering function and can be executed through the command-line interface.



CMake manages the project configuration and build process. The Windows launcher opens the browser-based dashboard from the packaged frontend directory.



The frontend provides a visual overview of the workbench modules and their results.





3\. INTEGRATION STATUS



The C++ core and frontend are currently separate components.



The frontend is a static dashboard prototype and is not connected to a live C++ transport or API. Engineering calculations are executed through the command-line application.



The hardware interfaces are simulated and do not communicate with physical devices.



These limitations are documented accurately and are not represented as completed functionality.





4\. BUILD AND EXECUTION



The project uses C++17 and CMake and was built on Windows using Microsoft Visual Studio C++ Build Tools.



The packaged application includes the Windows launcher, command-line executable, frontend, sample data, documentation and results.

