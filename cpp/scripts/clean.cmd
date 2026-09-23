@echo off
REM Clean the learning project's build directory and run output.
setlocal
cd /d "%~dp0.."
if errorlevel 1 exit /b 1

if exist build rmdir /s /q build
if exist bin rmdir /s /q bin
echo [learn] cleaned build\ and bin\
