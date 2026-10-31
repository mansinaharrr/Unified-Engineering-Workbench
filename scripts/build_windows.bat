@echo off
setlocal
cmake -S . -B build -A x64 -DCMAKE_BUILD_TYPE=Release
if errorlevel 1 exit /b 1
cmake --build build --config Release --parallel
if errorlevel 1 exit /b 1
ctest --test-dir build -C Release --output-on-failure
if errorlevel 1 exit /b 1
mkdir dist 2>nul
copy build\Release\uew.exe dist\Launch.exe
xcopy frontend dist\frontend\ /E /I /Y
xcopy data dist\data\ /E /I /Y
echo Windows build complete. Verify on a clean Windows 11 x64 machine before submission.
