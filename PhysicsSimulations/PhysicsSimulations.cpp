#include <iostream>
#include "pch.h"

#include <fstream>
#include "graphics.h"

int main() {
	// Initialize
	std::cout << "Instantiating objects in main" << std::endl;
	PhysicsEngine::World world;
	PhysicsEngine::RectangularPrism rectangle;
	PhysicsGraphics::Window window;
	PhysicsGraphics::GraphicsEngine graphicsEngine(&world, &window);

	std::cout << "Initializing window" << std::endl;
	window.initialize();
	std::cout << "Initializing graphics engine" << std::endl;
	graphicsEngine.initialize();


	// Function body

	std::cout << "Initializing world" << std::endl;
	rectangle.position << 1.0, 1.0, 1.0;
	rectangle.velocity << 0.0, 0.0, 0.0;
	rectangle.acceleration << 0.0, 0.0, 0.0;
	rectangle.width = 30.0;
	rectangle.length = 90.0;
	std::cout << rectangle.position.x() << "\n";
	world.entities.push_back(&rectangle);


	std::cout << "Starting event loop" << std::endl;
	graphicsEngine.startEventLoop(&window);
}