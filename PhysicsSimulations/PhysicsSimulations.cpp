
#include <iostream>
#include "world.h"
#include "rectangle.h"
#include "vector"

int main() {
    PhysicsEngine::World world;
    PhysicsEngine::Rectangle* rectangle = new(PhysicsEngine::Rectangle);

    (*rectangle).position << 1.0, 1.0, 1.0;
    (*rectangle).velocity << 0.0, 0.0, 0.0;
    (*rectangle).acceleration << 0.0, 0.0, 0.0;
    (*rectangle).width = 30.0;
    (*rectangle).length = 90.0;

    std::cout << (*rectangle).position.x() << "\n";

    world.entities.push_back(rectangle);

    delete rectangle;
}