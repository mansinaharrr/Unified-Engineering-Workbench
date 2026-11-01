@echo off
setlocal

echo ==========================================
echo  UNIFIED ENGINEERING WORKBENCH
echo  Windows x64 Build and Packaging
echo ==========================================

REM Locate project root (parent of scripts folder)
set "ROOT=%~dp0.."
set "DIST=%ROOT%\dist"

cd /d "%ROOT%"

echo.
echo [1/6] Configuring CMake...

cmake -S "%ROOT%" -B "%ROOT%\build" -A x64
if errorlevel 1 goto error

echo.
echo [2/6] Building Release configuration...

cmake --build "%ROOT%\build" --config Release --parallel
if errorlevel 1 goto error

echo.
echo [3/6] Running automated tests...

ctest --test-dir "%ROOT%\build" -C Release --output-on-failure
if errorlevel 1 goto error

echo.
echo [4/6] Preparing distribution folders...

if exist "%DIST%" rmdir /s /q "%DIST%"

mkdir "%DIST%"
mkdir "%DIST%\bin"

echo.
echo [5/6] Copying application files...

copy /Y "%ROOT%\build\Release\Launch.exe" "%DIST%\Launch.exe"
if errorlevel 1 goto error

copy /Y "%ROOT%\build\Release\uew.exe" "%DIST%\bin\uew.exe"
if errorlevel 1 goto error

xcopy "%ROOT%\frontend" "%DIST%\frontend\" /E /I /Y
if errorlevel 2 goto error

xcopy "%ROOT%\data" "%DIST%\data\" /E /I /Y
if errorlevel 2 goto error

if exist "%ROOT%\docs" (
    xcopy "%ROOT%\docs" "%DIST%\docs\" /E /I /Y
    if errorlevel 2 goto error
)

if exist "%ROOT%\results" (
    xcopy "%ROOT%\results" "%DIST%\results\" /E /I /Y
    if errorlevel 2 goto error
)

copy /Y "%ROOT%\README.md" "%DIST%\README.md"

echo.
echo [6/6] Packaging completed!

echo.
echo ==========================================
echo  BUILD SUCCESSFUL
echo ==========================================
echo.
echo Distribution folder:
echo %DIST%
echo.
echo Main launcher:
echo dist\Launch.exe
echo.
echo Run Launch.exe to open the dashboard.
echo The dashboard is a frontend prototype and
echo is not connected to the C++ backend.
echo.
pause
popd
exit /b 0

:error
echo.
echo ==========================================
echo  BUILD FAILED
echo ==========================================
echo Please check the error messages above.
pause
popd
exit /b 1