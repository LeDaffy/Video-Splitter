# Simple C program to split video using ffmpeg
## Description
Split a source video into multiple video files by providing timestamps and filename.

## Installation
Install ffmpeg to the system path.

Use `gcc -o splitter.exe splitter.c`
Place splitter.exe into the directory witht the source video

## Usage
Create a timestamp file following timestamps.txt. Do not include comments. Place the timestamps files in the same directory as the source video. Open the command prompt.

`splitter.exe -i source.mp4 -t timestamps.txt`

Commands
- -i input file name: use this to provide the source video that needs to be split into timecodes
- -t timestamps file name: use this to provide the timestamps file



