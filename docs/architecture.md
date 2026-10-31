# Architecture

- `include/uew.hpp`: public C++17 module interfaces.
- `src/thermal`: 1D linear-element finite element solver and analytical comparison.
- `src/geometry`: ASCII STL bounds/triangle parser and strict nodal CSV validator.
- `src/performance`: deterministic independent-case batch benchmark with serial and bounded worker execution.
- `src/hardware`: simulated MCU, FPGA and JTAG adapters with recoverable timeout path.
- `src/backpropagation`: hand-derived one-sample gradients, simultaneous update, finite-difference utility and training history.
- `src/main.cpp`: command-line entry point for repeatable module execution.
- `tests`: CTest-driven integration tests.
- `frontend`: dark engineering dashboard mock-up.
- `data`: self-created geometry and synthetic temperature sample.
- `results`: generated CSVs, plots, benchmark evidence and environment metadata.

The C++ core is separated from the presentation layer. In this deliverable, the frontend is a static dashboard prototype and is not yet connected to a live C++ transport/API. The current executable is a C++ command-line workbench. This is a material integration gap against the full brief and is not represented as complete.
