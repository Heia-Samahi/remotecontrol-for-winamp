# Introduction #

With the combination of the RemoteControl app for Android and the RemoteControl plugin for Winamp you can easily control the playback and Playlist of Winamp over wireless LAN.

Necessary is Winamp version 5.5 or later.


# Installation #

**Winamp Plugin:**
  1. Download the plugin from: http://code.google.com/p/remotecontrol-for-winamp/downloads/list
  1. Install the plugin

**Android app:**
  1. Download and install RemoteControl for Winamp from Android Market


# Setting up the connection #

**Winamp Plugin:**
  1. Start Winamp. Now the server plugin should show up.
  1. Make sure the plugin displays a local IP address.
  1. Make sure the plugin displays "Status: Waiting for client...".

**Android app:**
  1. Establish a wifi connection to the network with the Winamp computer.
  1. Now start the Android app.
  1. Hit "connect".



# HELP #

  * _The app displays "connection refused":_
> Establish a network connection to the same network as you computer with Winamp is in.
> In the Android app go to "Settings" and change the server IP address to the address displayed in the Winamp Plugin.
> Make sure the selected port is the same as set in the Winamp plugin.

  * _The app displays "timeout":_
> The plugin did not answer. Start it first and make sure there is no firewall blocking traffic on the selected port.

  * _Can I close the plugin without losing connection to the app?_
> Yes, the server runs in background if started.

  * _The plugin does not display a local IP address:_
> Set up a network connection.

  * _The plugin does not display "Status: Waiting for client...":_
> Hit the "Start server" button.

  * _The plugin displays "Port already connected":_
> Another program uses this port. Chose another one for the Winamp plugin and for the app.

  * _The plugin displays "Playlist out of sync!"_
> The Winamp playlist has changed. You have to establish a new connection to sync server and client.

  * _The plugin displays "Sending cover data failed!"_
> Cover data could not be read. Currently, cover files can be read from mp3 and flac files. If you wish to have another extension, tell me.

  * _The server plugin does not start although it is installed:_
> Run the installer again or manually install the [Microsoft Visual C++ 2010 Redistributable](http://www.microsoft.com/downloads/en/details.aspx?FamilyID=a7b7a05e-6de6-4d3a-a423-37bf0912db84&pf=true) and the [Microsoft .Net Framework 4](http://www.microsoft.com/downloads/en/details.aspx?displaylang=en&FamilyID=0a391abd-25c1-4fc0-919f-b21f31ab88b7&pf=true).