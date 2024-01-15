@echo off

set CMAKE="C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe"
set VCPKG="E:/vcpkg/scripts/buildsystems/vcpkg.cmake"

%CMAKE% -S. -B_build ^
	-DCMAKE_TOOLCHAIN_FILE=%VCPKG% ^
	-DTMPL_BUILD_TESTS=ON ^
	-DTMPL_BUILD_EXAMPLES=ON ^
	-DTMPL_EXCLUDE_DEPRECATED=ON ^
	-DTMPL_BUILD_DOCUMENTATION=ON

 pause
