@echo off
REM ---------------------------------------------------------------------------
REM lc-build.cmd - compile one LeetCode file together with utils.cpp.
REM No run, no cleanup: intended as a "build" step (e.g. a VSCode preLaunch).
REM
REM Toolchain: clang++ (LLVM) compiles, lld links, lldb debugs. The MSVC
REM environment is still initialized first, but only to get the Windows SDK
REM headers/libs and link.exe - clang drives the whole compile itself.
REM
REM Usage: scripts\lc-build.cmd <problem.cpp>
REM ---------------------------------------------------------------------------
setlocal
call "%~dp0msvc-env.cmd"
if errorlevel 1 exit /b 1

if "%~1"=="" (
    echo usage: lc-build.cmd ^<problem.cpp^> 1>&2
    exit /b 2
)

REM vcvars64 rewrites PATH, so the user-level LLVM entry does not survive it.
REM Put LLVM first so clang++ wins over anything Visual Studio ships.
set "LLVM_BIN=C:\Program Files\LLVM\bin"
if not exist "%LLVM_BIN%\clang++.exe" (
    echo [lc-build] ERROR: clang++ not found at "%LLVM_BIN%" 1>&2
    echo [lc-build] install LLVM 23.x, or edit LLVM_BIN above 1>&2
    exit /b 1
)
set "PATH=%LLVM_BIN%;%PATH%"

REM Resolve the argument to absolute SRC / DIR / STEM (relative paths included).
for %%F in ("%~1") do (
    set "SRC=%%~fF"
    set "DIR=%%~dpF"
    set "STEM=%%~nF"
)

pushd "%DIR%"
if errorlevel 1 exit /b 1

REM -g: emits CodeView debug info (lldb reads it fine).
REM -finput-charset/-fexec-charset=UTF-8: sources carry UTF-8 Chinese comments
REM and check.h has emoji.
REM -fuse-ld=lld: the LLVM linker, so clang owns the link step too.
clang++ -std=c++23 -finput-charset=UTF-8 -fexec-charset=UTF-8 -g -O0 "%SRC%" utils.cpp -o "%STEM%.exe" -fuse-ld=lld
set "RC=%errorlevel%"

if "%RC%"=="0" del "%STEM%.obj" "%STEM%.ilk" utils.obj >nul 2>nul
popd
exit /b %RC%
