# (WIP) Physics Simulator

A 2D physics engine for simulating collisions, gravity, momentum, forces, and more.

## Components

### PhysicsMath

Local project-specific math static library providing data types such as vectors, matrices, and relevant operations/methods.

### PhysicsEngine

Provides all the logic and data types needed to represent a world along with the main time-step simulation function that advances the world state.

### PhysicsSimulations

Makes use of the physics engine in a rendered world to demonstrate capabilities of the engine.

## Development

1. Clone repo
2. Get dependencies by running `git submodule update --init --recursive`
3. Open solution in Visual Studio
4. Running will run `PhysicsSimulations/PhysicsSimulations.cpp:main`