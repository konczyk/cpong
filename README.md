# CPong 

Simple Pong clone written in C, using SDL3.

## Build

### cmake

Install `cmake` 3.30 or later from your Linux distribution or use `brew` on osx.

### SDL3

Download and unpack [SDL3](https://github.com/libsdl-org/SDL/releases/download/release-3.2.12/SDL3-3.2.12.tar.gz) into `vendor/SDL3` directory  
Download and unpack [SDL3_ttf](https://github.com/libsdl-org/SDL_ttf/releases/download/release-3.2.2/SDL3_ttf-3.2.2.tar.gz) into `vendor/SDL3_ttf` directory  
Save a TTF font, e.g. [ByteBounce Medium](https://www.1001fonts.com/download/font/bytebounce.medium.ttf) (for some retro look) as `data/font.ttf` file

### Compile

    $ cmake -DCMAKE_BUILD_TYPE=Release -B bin
    $ cmake --build bin

## Run

    $ ./bin/cpong
