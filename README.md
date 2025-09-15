# (WIP) Physics Simulator

A 2D physics engine for simulating collisions, gravity, momentum, forces, and more.

## Components

### (WIP) PhysicsEngine

Provides all the logic and data types needed to represent a world along with the main time-step simulation function that advances the world state.

### (WIP) PhysicsSimulations

Makes use of the physics engine in a rendered world to demonstrate capabilities of the engine.

## Development

### Install GLAD

1. Download zip file from this [Pre-Configured URL](https://glad.dav1d.de/#language=c&specification=gl&api=gl%3D4.6&api=gles1%3D1.0&api=gles2%3D3.2&api=glsc2%3D2.0&profile=core&loader=on)
2. Copy folders inside include directory into `./PhysicsSimulations/include/`
3. Copy `glad.c` into `./PhysicsSimulations/glad/`

### Setup

1. Clone repo
2. Get dependencies by running `git submodule update --init --recursive`
3. Open solution in VS Code
4. Run `cmake -S . -G "MinGW Makefiles"` to generate build files for MinGW (Can be installed through this [tutorial](https://code.visualstudio.com/docs/cpp/config-mingw#_prerequisites))
5. Running will compile and run `PhysicsSimulations/PhysicsSimulations.cpp:main`
