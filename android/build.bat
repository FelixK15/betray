@echo off
setlocal enableextensions enabledelayedexpansion

set scriptPath=%~dp0
set bashPath=%SystemRoot%\System32\bash.exe

if exist %bashPath% (
	set command=bash build.sh
	!command!
) else (
	echo Could not find WSL installation, please install WSL using the 'wsl --install' cmd inside powershell.
	pause
)