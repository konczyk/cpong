# CPong 

Pong clone written in C and using SDL3.

## Build

Install `cmake` 3.30 or later from your Linux distribution.

By default, SDL3 shared library is used to build the executable:

    $ cmake -B bin
    $ cmake --build bin

If you don't have SDL3 installed, or you want to use the source package,
download and unpack [SDL3](https://github.com/libsdl-org/SDL/releases/download/release-3.2.12/SDL3-3.2.12.tar.gz) into `vendor/SDL3` and
[SDL3_ttf](https://github.com/libsdl-org/SDL_ttf/releases/download/release-3.2.2/SDL3_ttf-3.2.2.tar.gz) into `vendor/SDL3_ttf`, then execute:

    $ cmake -DVENDOR=ON -B bin 
    $ cmake --build bin

## Run

    $ ./bin/cpong

## Controls

Left player moves with `W` and `S` keys, right player moves with `UP` and `DOWN` arrow keys. `SPACE` starts the game.

![cpong](cpong.png)

The WDXL Lubrifont TC font is licensed under the [SIL Open Font License, Version 1.1](data/OFL.txt).

