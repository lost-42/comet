@echo off
REM ---------------------------------------------------------------------------
REM lc.cmd - build, run and clean up one LeetCode file.
REM
REM Usage: scripts\lc.cmd <problem.cpp>
REM
REM Replaces the old POSIX lc.sh: uses MSVC (cl) instead of clang++/libc++, and
REM works from cmd / PowerShell / an editor task without a WSL shell.
REM ---------------------------------------------------------------------------
setlocal
call "%~dp0lc-build.cmd" "%~1"
if errorlevel 1 exit /b 1

for %%F in ("%~1") do (
    set "DIR=%%~dpF"
    set "STEM=%%~nF"
)

pushd "%DIR%"
if errorlevel 1 exit /b 1

REM Programs are built with /utf-8 and print UTF-8 bytes; make the console
REM decode them as UTF-8 too (otherwise GBK 936 shows mojibake).
chcp 65001 >nul

"%STEM%.exe"
set "RC=%errorlevel%"

del "%STEM%.exe" >nul 2>nul
popd
exit /b %RC%
