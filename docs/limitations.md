# Known Limitations

1. Dashboard: The packaged Windows launcher opens the local static dashboard in the default browser. The dashboard and C++ command-line executable are separate; there is no live frontend-to-backend connection.

2. 3D Visualization: ASCII STL parsing and bounding-box calculation are implemented. Interactive triangle rendering, rotate, pan, zoom, fit-to-view, temperature point-cloud rendering, colour legend and node inspection are not implemented.

3. CSV Data: The required nodal CSV schema is validated. The supplied temperature dataset is synthetic and is not an ANSYS export.

4. Embedded Hardware: MCU, FPGA and JTAG behaviour is simulated in software. No physical hardware communication or firmware programming is performed.

5. Benchmarking: Performance measurements depend on the host system. Worker creation is included in the timed region, so results may vary between runs.

6. Windows Packaging: The supplied launcher and CLI executable were built and the launcher was manually checked after extraction on the development machine. A separate clean-machine test was not performed.

7. Demo Evidence: A separate timestamped screenshot walkthrough or demo video must accompany the final submission.