# vlc-controller

ESP8266 controller for pause/play function of VLC media player.

When the python file runs, it creates a local flask server which the ESP8266 can make a request to.

A button click on the ESP8266 will make a HTTP request to the flask server.

Each request will trigger:
  a) the VLC window being pushed to the forground. Usually it will already be in the foreground, but this is to make sure the next step executes on the correct program.
  b) sends a virtual space bar event which pauses or continues playback on VLC.


Fritzing Diagram for ESP8266 hookup:




![alt text](https://github.com/turner-prize/vlc-controller/blob/master/esp8266-sketch/breadboard-diagram_bb.png?raw=true)
