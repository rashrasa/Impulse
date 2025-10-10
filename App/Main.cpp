#include <iostream>

#include "Impulse/Impulse.h"

int main() {
	// Initialize
	std::cout << "Instantiating objects in main" << std::endl;
	std::shared_ptr<Impulse::Core::World> world = std::shared_ptr<Impulse::Core::World>(
		new Impulse::Core::World()
	);
	std::shared_ptr<Impulse::Render::Window> window = std::shared_ptr<Impulse::Render::Window>(
		new Impulse::Render::Window()
	);

	Impulse::Render::GraphicsEngine graphicsEngine(world, window);

	std::cout << "Initializing window" << std::endl;
	(*window).initialize();

	// Function body
	std::cout << "Initializing world" << std::endl;
	(*world).addEntity(
		new Impulse::Core::RectangularPrism(Eigen::Vector3f(1.0f, 1.0f, 1.0f), 1.0f, 1.0f, 1.0f)
	);

	std::cout << "Initializing graphics engine" << std::endl;
	graphicsEngine.initialize();
	std::cout << "Starting event loop" << std::endl;
	graphicsEngine.startEventLoop();
}