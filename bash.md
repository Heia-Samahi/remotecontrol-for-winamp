# Introduction #

The Unix bash (Bourne-again-shell) allows simple control mechanisms for the RemoteControl plugin. The usage is described below.


# Details #

  1. Open the bash window
  1. Connect to the Winamp plugin with
```
  exec 3<>/dev/tcp/IPADDRESS/PORT
```
  1. To send a command use
```
   echo -e "COMMAND\0" >&3
```
> where COMMAND is one of the following commands listed here:
http://code.google.com/p/remotecontrol-for-winamp/wiki/Protocol?ts=1312994650&updated=Protocol#Controling_Winamp