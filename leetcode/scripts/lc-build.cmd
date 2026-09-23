@echo off
REM ---------------------------------------------------------------------------
REM lc-build.cmd - compile one LeetCode file together with utils.cpp.
REM No run, no cleanup: intended as a "build" step (e.g. a VSCode preLaunch).
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

REM Resolve the argument to absolute SRC / DIR / STEM (relative paths included).
for %%F in ("%~1") do (
    set "SRC=%%~fF"
    set "DIR=%%~dpF"
    set "STEM=%%~nF"
)

pushd "%DIR%"
if errorlevel 1 exit /b 1

REM /Z7 embeds CodeView debug info in the object (no stray .pdb files).
REM /utf-8: sources carry UTF-8 Chinese comments and check.h has emoji.
REM /link /INCREMENTAL:NO: avoid leaving an .ilk next to the source file.
cl /nologo /std:c++latest /EHsc /utf-8 /Z7 /Od "%SRC%" utils.cpp /Fe:"%STEM%.exe" /link /INCREMENTAL:NO
set "RC=%errorlevel%"

if "%RC%"=="0" del "%STEM%.obj" "%STEM%.ilk" utils.obj >nul 2>nul
popd
exit /b %RC%
