# AI-use log

AI assistance was used to draft code structure, implementation scaffolding, documentation and test cases. The candidate must update this log with the actual assistant/tool names, dates, prompts, accepted outputs, edits and validation performed before submission.

## Challenge test and correction evidence
An initial thermal test incorrectly expected the midpoint error to be below 1e-8 °C. The test failed because the linear FE interpolation of the quadratic analytical profile has a nonzero midpoint interpolation error, equal here to q h²/(8k). The test threshold was corrected to a physically meaningful bound for the 40-element mesh, and the measured convergence sequence was checked: 1.25, 0.3125, 0.078125 and 0.01953125 °C for 10, 20, 40 and 80 elements respectively.

Do not claim an interaction or validation that did not occur. Add the actual AI model/version and your own edits.
