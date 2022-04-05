## Instructions ##
If you want to build the android version on windows you can do so by installing wsl1 (Windows Subsystem for Linux).
In theory you should be good by just running build.bat after installing wsl1, however there are some things to do before doing so.

### Prerequisites ###
This script was only tested with an Ubuntu WSL installation. If you want to run this script on another distro, you're on your own.

Before you can go, a few prerequisites have to be met.
First of all, be sure that the aptitude repo is up to date by running `sudo apt-get update` before doing anything else.

Since line endings are different between windows & linux, you have to manually change the line endings to be able to run
the build.sh script using wsl. A tool called 'dos2unix' can be used for that. Make sure you install dos2unix by running
`sudo apt-get install dos2unix`. After dos2unix is installed you have to run `sudo dos2unix build.sh` *once* to change the
line endings.

Additionally, you might have to set the correct file permissions for the access from WSL to the build directory.
You can that by creating `etc/wsl.conf` inside the WSL bash with the following content:
```
[automount]
enabled = true
options = "metadata,umask=22,fmask=11"
```

After that you should be able to run build.bat or build.sh within WSL to create a new android version.