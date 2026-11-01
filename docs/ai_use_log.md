**AI USE LOG**



1\. AI TOOL USED



Tool: ChatGPT

Model: GPT-6

Period of assistance: 31 October – 1 November 2026





2\. AREAS WHERE AI ASSISTANCE WAS USED



Project Architecture: Suggested the modular project structure and organization.



C++ Implementation: Assisted with implementation of thermal, geometry, performance, hardware and backpropagation modules.



Thermal Analysis: Assisted with numerical calculations, error analysis and test correction.



Frontend: Assisted with HTML, CSS and JavaScript dashboard development.



Windows Integration: Assisted with launcher implementation, CMake configuration and build scripts.



Debugging: Helped identify build issues, command usage errors and configuration problems.



Documentation: Assisted with technical report, architecture documentation and mathematical derivation.





3\. IMPORTANT PROMPTS AND ACCEPTED ASSISTANCE



\- Requested a modular engineering workbench combining numerical analysis, geometry processing, performance benchmarking, hardware simulation and backpropagation.

\- Requested assistance with implementing and debugging the individual C++ modules.

\- Requested a professional engineering dashboard and Windows launcher.

\- Requested help configuring and packaging the application using CMake and Visual Studio Build Tools.

\- Requested explanations and mathematical derivations matching the backpropagation implementation.

\- Requested assistance preparing technical documentation and project verification evidence.





4\. CANDIDATE CONTRIBUTIONS AND MODIFICATIONS



The candidate configured the Windows development environment, built the application, executed the individual modules, verified the packaged launcher, reviewed the dashboard, and checked the automated test results.



The candidate reviewed the AI-assisted implementation and used the application outputs to verify its behaviour.





5\. TESTING AND VALIDATION



\- Thermal module executed successfully for 10, 20, 40 and 80 elements.

\- Geometry module successfully processed the supplied STL file.

\- CSV validation reported 11 validated nodes.

\- Performance benchmark executed with 1, 2 and 4 workers.

\- Backpropagation gradients were compared against finite-difference estimates.

\- Hardware module demonstrated simulated telemetry and timeout handling.

\- CMake Release build completed successfully.

\- CTest completed with 1 test passed and 0 failures.

\- Packaged Windows launcher successfully opened the dashboard.





6\. THERMAL TEST CORRECTION EVIDENCE



An initial thermal test incorrectly expected the midpoint error to be below 1e-8 °C. The test failed because linear finite-element interpolation of the quadratic analytical profile produces a nonzero midpoint interpolation error.



The test threshold was corrected to a physically meaningful bound for the 40-element mesh.



The measured convergence results were:



Elements          Midpoint Error (°C)

10                1.25

20                0.3125

40                0.078125

80                0.01953125





7\. DISCLOSURE



AI assistance was used extensively during project development. The candidate reviewed and tested the resulting implementation. The use of AI assistance is disclosed to maintain transparency regarding the development process.



All verification claims in this log refer to the tests actually performed during the project.

