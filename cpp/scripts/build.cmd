@echo off
REM ---------------------------------------------------------------------------
REM build.cmd - configure + build the C++ learning project (cpp/).
REM Environment/bootstrap is shared by run.cmd so both editors and terminals
REM go through exactly one code path.
REM ---------------------------------------------------------------------------
setlocal
call "%~dp0msvc-env.cmd"
if errorlevel 1 exit /b 1

cd /d "%~dp0.."
if errorlevel 1 exit /b 1

cmake --preset win-msvc-debug
if errorlevel 1 exit /b 1

cmake --build --preset win-msvc-debug
