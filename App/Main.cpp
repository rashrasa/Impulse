#include <iostream>

#include "Impulse/Impulse.h"

int main() {
	// Initialize
	std::cout << "Instantiating objects in main" << std::endl;
	impulse::core::World world;
	impulse::core::RectangularPrism* rectangle = new impulse::core::RectangularPrism(Eigen::Vector3f(1.0f, 1.0f, 1.0f), 1.0f, 1.0f, 1.0f);
	impulse::render::Window window;
	impulse::render::GraphicsEngine graphicsEngine(&world, &window);

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