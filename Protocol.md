# Introduction #

The network traffic of RemoteControl for Winamp is not encrypted. Feel free to use the Winamp plugin or the Android app to enlarge functionalities.


# Synchronization #

**When a client connects to the server app, the playback status is synchronized. The server automatically sends these messages with the corresponding meaning. Each message is terminated by the new line '\n' character.**

  1. length of playlist
  1. title of every track in playlist
  1. repeat status (1: on, 0:off)
  1. shuffle status (1: on, 0:off)
  1. volume (0..255)
  1. number of elements in wasabi queue
  1. track number of every element in wasabi queue
  1. samplerate
  1. bitrate
  1. length
  1. number of currently playing title within playlist
  1. title of currently playing track
  1. playback position in seconds
  1. playback status (1: playing, 3: paused, 0: not playing (stopped))
  1. cover size in bytes
  1. cover data


# Controling Winamp #

**The Winamp server plugin can be controlled with these commands. Each command has to be terminated by a '\0' character.**

| **string to send** | **Winamp action** | **comment** |
|:-------------------|:------------------|:------------|
| play               | starts playback   |             |
| pause              | pauses playback   |             |
| previous           | previous track    |             |
| next               | next track        |             |
| shuffle            | toggle shuffle    |             |
| repeat             | toggle repeat     |             |
| mute               | mute/unmute       |             |
| volume\_X          | set volume to X   | 0 <= X <= 255 |
| progress\_X        | set playback position within track to X seconds |             |
| playlistitem\_X    | play file number X in playlist |             |
| enqueue\_X         | use wasabi api\_queue service to enqueue track X from playlist |             |
| remqueue\_X        | remove track X from api\_queue service |             |
| trackInfo\_X       | get TAG information for track number X in the playlist | the server answers with track\_title\_X, track\_artist\_X, track\_album\_X, track\_year\_X, track\_track\_X, track\_genre\_X, track\_samplerate\_X, track\_bitrate\_X, track\_length\_X, track\_comment\_X, track\_X. See below. |


# Information messages from the server #

**The Winamp plugin tells the client about events with the following commands. Each command is terminated by the new line '\n' character.**

| **string sent by the server plugin** | **meaning** | **comment** |
|:-------------------------------------|:------------|:------------|
| isplaying\_X                         | playback status has changed by user action | Winamp is 1: playing, 3: paused, 0: not playing (stopped) |
| playlistPosition\_X                  | element X of the playlist is playing |             |
| samplerate\_X                        | currently playing title has the samplerate X |             |
| bitrate\_X                           | currently playing title has the bitrate X |             |
| length\_X                            | currently playing title has the length X in seconds |             |
| title\_X                             | currently playing element in playlist has the title X | displayed in the playlist |
| coverLength\_X                       | if X > 0 the next X bytes are the cover picture data | picture data is not terminated by '\n' |
| volume\_X                            | volume has been changed to X | 0 <= X <= 255 |
| progress\_X                          | the playback position within the currently playing track has been changed manually to X seconds |             |
| queue\_next                          | next element from wasabi api\_queue service has been chosen |             |
| pause                                | playback has been paused |             |
| stop                                 | playback has been stopped|             |
| shuffle\_X                           | shuffle (de-)activated | X==1: on, X==0: off |
| repeat\_X                            | reapeat (de-)activated | X==1: on, X==0: off |
|                                      |             |
| track\_title\_X                      | requested title, read from TAG header |             |
| track\_artist\_X                     | requested artist, read from TAG header |             |
| track\_album\_X                      | requested album, read from TAG header |             |
| track\_year\_X                       | requested year, read from TAG header |             |
| track\_genre\_X                      | requested genre, read from TAG header |             |
| track\_samplerate\_X                 | requested sample rate, read from TAG header |             |
| track\_bitrate\_X                    | requested bit rate, read from TAG header |             |
| track\_length\_X                     | requested length in seconds, read from TAG header |             |
| track\_comment\_X                    | requested comment, read from TAG header |             |
| track\_X                             | requested cover length. if X > 0 the next X bytes are the cover picture data | picture data is not terminated by '\n' |

When a new track has started playing the commands isplaying\_X, playlistPosition\_X, samplerate\_X, bitrate\_X, length\_X, title\_X, cover\_X and the cover data are always sent in this order.

# <font color='#FF0000'>IMPORTANT</font> #

**If keep alive messages are enabled in the server**

Every 5 seconds the server plugin sends the string "alive\n" to the client. If the client didn't answer with "alive\0" for 3 times (=15 seconds) the server assumes the client has lost connection and the server is restarted.