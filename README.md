# Hackaday 2023

Hackaday Supercon gives you a badge, it's a single board computer. Supercon invites you to hack the badge. My hack is to get it to display and play video from the Web. I got it to work! The badge plays mjpeg video. I wrote a screen capture utility in Javascript, it uses ffmpeg to convert to 240x240 pixels, and crops to the selection box on the page. I modified the badge by replacing the Pico board with an ESP32-S3-Mini dev module and adding an SD card. I use Wifi to get the captured video onto the SD, then use a JPEG decoder to display the video frames. I am feeling nerd-tas-tic!

The controller on the badge's video display appears to be really, really slow. I get 10 frames per second using a different 1 data line controller.

- Frank Cohen, November 2, 2023, part of the [Reflections](https://github.com/frankcohen/ReflectionsOS) open-source project
