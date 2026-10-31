@echo off
setlocal
cmake -S . -B build -A x64 -DCMAKE_BUILD_TYPE=Release
if errorlevel 1 exit /b 1
cmake --build build --config Release --parallel
if errorlevel 1 exit /b 1
ctest --test-dir build -C Release --output-on-failure
if errorlevel 1 exit /b 1
mkdir dist\bin 2>nul
copy build\Release\uew.exe dist\bin\uew.exe
xcopy frontend dist\frontend\ /E /I /Y
xcopy data dist\data\ /E /I /Y
echo C++ Windows CLI build complete. No GUI Launch.exe is produced by this script.
echo Complete the frontend-to-backend integration and clean-machine packaging before submission.
