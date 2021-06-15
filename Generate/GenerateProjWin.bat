@echo off
pushd %~dp0\..\
call Premake\Binary\Premake\premake5.exe vs2019
popd
PAUSE