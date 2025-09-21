#include <iostream>

#include "Impulse/Impulse.h"

int main() {
	// Initialize
	std::cout << "Instantiating objects in main" << std::endl;
	Impulse::Core::World world;
	Impulse::Core::RectangularPrism* rectangle = new Impulse::Core::RectangularPrism(Eigen::Vector3f(1.0f, 1.0f, 1.0f), 1.0f, 1.0f, 1.0f);
	Impulse::Render::Window window;
	Impulse::Render::GraphicsEngine graphicsEngine(&world, &window);

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