# Simple C program to split video using ffmpeg

## Installation
Install ffmpeg to the system path.
Use `gcc -o splitter.exe splitter.c`
Place splitter.exe into the directory witht the source video

Commands
-i input file name: use this to provide the source video that needs to be split into timecodes
-t timestamps file name: use this to provide the timestamps file

The timestamp file should look like this. Erase comments
3                               // Number of videos to create
00:01:34 Title1.mkv             // Start timestamp of the video and then the first title. Follow the format hh:mm:ss for the timecode
00:04:27 Title2.mkv             // Beginning of the next video and then the next title
00:10:00                        // The last line is the end timestamp of your final video do not include a title.