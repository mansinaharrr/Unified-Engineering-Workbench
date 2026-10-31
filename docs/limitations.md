# Known limitations and honest status

1. The workspace used to build this deliverable is Linux. A native Windows 11 x64 `Launch.exe` cannot be produced or clean-machine-verified here. `scripts/build_windows.bat` is provided for a Windows build host; its output must be tested on a clean Windows 11 x64 machine. The script does not create or mislabel a `Launch.exe` GUI launcher.
2. The delivered executable is a C++ command-line workbench. `frontend/` is a polished static UI concept but does not yet call the C++ backend. Therefore the one-coherent-interface and responsive live progress requirements are not fully met.
3. STL support is ASCII STL only. Binary STL is out of scope. CSV is strictly validated against the exact required header. Mesh rendering, camera controls, 3D point-cloud rendering and node inspection are not implemented in the static UI.
4. Hardware behaviour is simulated. No physical boards, pinout validation, firmware, PCB or FPGA programming were performed.
5. Benchmark measurements are host-specific and include worker creation in the timed region. The one-worker case is serial; two/four-worker cases use a bounded number of standard threads. Timing data is an observed run, not a performance guarantee.
6. The handwritten derivation is supplied as a typed study appendix. The candidate must manually reproduce it legibly and submit their own scan/photo; no handwritten evidence is fabricated.
7. The ZIP is a source-and-Linux-build prototype. Final Windows packaging, runtime dependency audit and clean-machine launch validation remain to be done.
