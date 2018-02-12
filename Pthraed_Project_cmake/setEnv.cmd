@echo off
set BUILD_TYPE=%1

set ARCH=%2


set CURR_PATH=%~dp0
set SOURCE_PATH=%~dp0
set PROJ_PATH=%CURR_PATH%
echo *************

set TOOLS_PATH=NOTFOUND
set TOOLS_BIN_PATH=NOTFOUND
set CMAKE_MODULE_PATH=NOTFOUND
set CUDA_LIB_PATH=NOTFOUND
echo ********************** Setting VS PATH ********************************
if exist %VCInstallDir% (
	echo *************
	set VS_PATH=%VCInstallDir%
	set VSPATHROOT=%VCInstallDir%
	set GCCCOMPIERPATH=%VCInstallDir%bin
) ELSE (
	echo *************
	echo VS not installed.
	echo *************
)

echo VS path %VS_PATH%
	echo VS path Root %VSPATHROOT%
	echo VS Compiler Path %GCCCOMPIERPATH%
echo ********************** End of Setting VS PATH ********************************

echo ********************** Setting OPENCV PATH ********************************
set OPENCV_PATH=C:\openCV2.3.1

echo "%OPENCV_PATH%"
::SETLOCAL ENABLEDELAYEDEXPANSION
if exist "%OPENCV_PATH%" (
	set OPENCV_ROOT_PATH=%OPENCV_PATH%
	set OPENCV_INCLUDE_PATH=%OPENCV_PATH%\opencv\include
	if "%ARCH%"=="64" (
		set OPENCV_LIB_PATH=%OPENCV_PATH%\opencv\build\x64\vc10\lib
		set OPENCV_BIN_PATH=%OPENCV_PATH%\opencv\build\x64\vc10\bin
		set OPENCV_STATICLIB_PATH=%OPENCV_PATH%\opencv\build\x64\vc10\staticlib
	) ELSE (
		set OPENCV_LIB_PATH=%OPENCV_PATH%\opencv\build\x86\vc10\lib
		set OPENCV_BIN_PATH=%OPENCV_PATH%\opencv\build\x86\vc10\bin
		set OPENCV_STATICLIB_PATH=%OPENCV_PATH%\opencv\build\x86\vc10\staticlib
	)
	
) 
echo %OPENCV_LIB_PATH%
echo %OPENCV_BIN_PATH%
echo %OPENCV_STATICLIB_PATH%
::ENDLOCAL
echo ********************** End of Setting OPENCV PATH ********************************
echo %PROJ_PATH%tools
echo ********************** Setting Tools PATH ********************************
if exist "%PROJ_PATH%tools" (
	set TOOLS_PATH=%PROJ_PATH%tools
	echo Cmake Modules Path Set	
)
echo ********************** End of Setting Tools PATH ********************************
echo "%TOOLS_PATH%"
rem Exports paths to PATH Enviroment
set PTHREAD_PATH=%PROJ_PATH%tools\pthread\Pre-built.2
set PTHREAD_LIB_PATH=%PTHREAD_PATH%\lib
set PTHREAD_BIN_PATH=%PTHREAD_PATH%2\bin
set PTHREAD_INC_PATH=%PTHREAD_PATH%\include
set TOOLS_BIN_PATH=%PROJ_PATH%tools\bin
set CMAKE_MODULE_PATH=%PROJ_PATH%tools\bin
	
PATH=%TOOLS_BIN_PATH%;%GCCCOMPIERPATH%;%TOOLS_PATH%\cmake-2.8.11.2-win32-x86\bin;%OPENCV_ROOT_PATH%;%OPENCV_BIN_PATH%;%OPENCV_LIB_PATH%;%PATH%;
echo %PATH%
set CMAKE_MODULE_PATH=%CMAKE_MODULE_PATH:\=/%

echo "%CMAKE_MODULE_PATH%"
echo "%CAKE_MODULE_PATH%"
echo   + CMake path set

echo   + PATH set to include tools/bin, tools/cmake as well as opencv and opencv/bin

:done
prompt=$p[i386_vc]$g


