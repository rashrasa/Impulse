# (WIP) Impulse

A 3D physics engine for simulating collisions, gravity, momentum, forces, and more.

## Components

### (WIP) ImpulseCore

Essential library containing type definitions, logging, event system, utilities.

### (WIP) ImpulsePhysics

Provides all the logic needed to simulate a world along with the main time-step simulation function that advances the world state.

### (WIP) ImpulseRender

Rendering library for displaying world objects.

### (Planned) ImpulseAudio

Audio library for events like collisions.

### (WIP) App

Makes use of the physics engine in a rendered world to demonstrate capabilities of the engine.

## Development

### Install GLAD

1. Download zip file from this [Pre-Configured URL](https://glad.dav1d.de/#language=c&specification=gl&api=gl%3D4.6&api=gles1%3D1.0&api=gles2%3D3.2&api=glsc2%3D2.0&profile=core&loader=on)
2. Copy folders inside include directory into `./Impulse/Render/include/`
3. Copy `glad.c` into `./Impulse/Render/glad/`

### Setup

1. Clone repo
2. Get dependencies by running `git submodule update --init --recursive`
3. Open solution in VS Code
4. Run `cmake -B build_mingw -G "MinGW Makefiles"` to generate build files for MinGW (Can be installed through this [tutorial](https://code.visualstudio.com/docs/cpp/config-mingw#_prerequisites))
5. Running will compile and run `App/Main.cpp:main`
