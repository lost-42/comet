@echo off
REM ---------------------------------------------------------------------------
REM msvc-env.cmd - initialize the MSVC x64 build environment and make the
REM Visual Studio bundled CMake / Ninja available on PATH.
REM
REM It MUST be "call"ed (not executed) from an existing cmd session, e.g.
REM     call scripts\msvc-env.cmd && cmake --preset win-msvc-debug
REM because environment changes only live in the calling cmd process.
REM
REM Why this exists: the Ninja generator does NOT initialize the MSVC
REM environment for you (the Visual Studio generator does). cl.exe needs
REM INCLUDE / LIB / PATH, which is exactly what vcvars64.bat sets up. Keeping
REM this in a script (instead of an editor setting) makes it reusable from
REM Zed, VSCode, CI, a plain terminal - anything.
REM ---------------------------------------------------------------------------

set "VSWHERE=%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe"
if not exist "%VSWHERE%" goto :no_vswhere

set "VSPATH="
for /f "usebackq tokens=*" %%i in (`"%VSWHERE%" -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath`) do set "VSPATH=%%i"
if not defined VSPATH goto :no_vs

call "%VSPATH%\VC\Auxiliary\Build\vcvars64.bat" >nul
if errorlevel 1 goto :vcvars_failed

REM Expose the CMake / Ninja that ship with Visual Studio, but only when the
REM user does not already have them on PATH.
where cmake >nul 2>nul
if errorlevel 1 set "PATH=%VSPATH%\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin;%PATH%"
where ninja >nul 2>nul
if errorlevel 1 set "PATH=%VSPATH%\Common7\IDE\CommonExtensions\Microsoft\CMake\Ninja;%PATH%"

echo [msvc-env] MSVC x64 environment ready ^(cl / cmake / ninja^)
set "VSWHERE="
set "VSPATH="
exit /b 0

:no_vswhere
echo [msvc-env] ERROR: vswhere.exe not found: "%VSWHERE%" 1>&2
exit /b 1

:no_vs
echo [msvc-env] ERROR: no Visual Studio with the C++ toolset was found 1>&2
exit /b 1

:vcvars_failed
echo [msvc-env] ERROR: vcvars64.bat failed 1>&2
exit /b 1
