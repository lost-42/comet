@echo off
REM ---------------------------------------------------------------------------
REM lc.cmd - build, run and clean up one LeetCode file.
REM
REM Usage: scripts\lc.cmd <problem.cpp>
REM
REM Toolchain: clang++ (LLVM) compiles, lld links. Replaces the old POSIX
REM lc.sh (which needed WSL and libc++) and the earlier MSVC cl.exe build;
REM works from cmd / PowerShell / an editor task on Windows.
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

REM Programs are built with UTF-8 and print UTF-8 bytes; make the console
REM decode them as UTF-8 too (otherwise GBK 936 shows mojibake).
chcp 65001 >nul

"%STEM%.exe"
set "RC=%errorlevel%"

del "%STEM%.exe" "%STEM%.pdb" >nul 2>nul
popd
exit /b %RC%
