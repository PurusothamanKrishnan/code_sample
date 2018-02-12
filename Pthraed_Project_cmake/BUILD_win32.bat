@echo on
pushd .
set BUILD_TYPE=%1
echo "%BUILD_TYPE%"
if "%BUILD_TYPE%"=="" (
  set BUILD_TYPE=Debug 
)
call setEnv.cmd %BUILD_TYPE%

set BUILD_DIR=%PROJ_PATH%\build\%BUILD_TYPE%
if not exist %BUILD_DIR% (
	echo  * Creating build directory in parent folder
	md %BUILD_DIR%
)
cd %BUILD_DIR%

call toolchain_win_vc_x86X64 %BUILD_TYPE% ".."


if %ERRORLEVEL% NEQ 0 (
  echo Error in creating the solution
  pause
) ELSE (
	start PTHREAD_SAMPLE.sln
)

::@echo %cmdcmdline% | findstr /l "\"\"" >NUL
::popd
::exit
