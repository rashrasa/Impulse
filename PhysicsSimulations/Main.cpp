#include <iostream>
#include <fstream>

#include "PhysicsEngine.h"
#include "Graphics.h"

int main() {
	// Initialize
	std::cout << "Instantiating objects in main" << std::endl;
	PhysicsEngine::World world;
	PhysicsEngine::RectangularPrism* rectangle = new PhysicsEngine::RectangularPrism(Eigen::Vector3f(1.0f, 1.0f, 1.0f), 1.0f, 1.0f, 1.0f);
	PhysicsGraphics::Window window;
	PhysicsGraphics::GraphicsEngine graphicsEngine(&world, &window);

	std::cout << "Initializing window" << std::endl;
	window.initialize();

	// Function body
	std::cout << "Initializing world" << std::endl;
	world.entities.push_back(rectangle);

	std::cout << "Initializing graphics engine" << std::endl;
	graphicsEngine.initialize();
	std::cout << "Starting event loop" << std::endl;
	graphicsEngine.startEventLoop(&window);
}