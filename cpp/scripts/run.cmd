@echo off
REM ---------------------------------------------------------------------------
REM run.cmd - build then run the C++ learning project (cpp/).
REM Editors (Zed / VSCode) invoke this instead of chaining commands with &&,
REM because on Windows the editor shell is often Windows PowerShell 5.1 which
REM does not understand &&. Keeping the chaining inside a .cmd makes the task
REM independent of the editor's shell.
REM ---------------------------------------------------------------------------
setlocal
call "%~dp0build.cmd"
if errorlevel 1 exit /b 1

cd /d "%~dp0.."
if errorlevel 1 exit /b 1

REM The program prints UTF-8; make the console decode it as UTF-8.
chcp 65001 >nul

bin\learn.exe
