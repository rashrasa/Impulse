#define GLFW_INCLUDE_NONE
#include <iostream>
#include "pch.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

static void error_callback(int error, const char* description) {
	std::cerr << "Error: " << description << std::endl;
}

int main() {
	// Initialize
	if (!glfwInit()) {
		throw "Could not initialize GLFW";
	}
	glfwSetErrorCallback(error_callback);
	auto window = glfwCreateWindow(640, 480, "Physics Simulations", NULL, NULL);
	if (!window) {
		throw "Could not create window";
	}
	glfwMakeContextCurrent(window);
	gladLoadGL();
	PhysicsEngine::World world;
	PhysicsEngine::RectangularPrism rectangle;

	// Function body
	rectangle.position << 1.0, 1.0, 1.0;
	rectangle.velocity << 0.0, 0.0, 0.0;
	rectangle.acceleration << 0.0, 0.0, 0.0;
	rectangle.width = 30.0;
	rectangle.length = 90.0;
	std::cout << rectangle.position.x() << "\n";
	world.entities.push_back(&rectangle);

	// Main event loop
	while (!glfwWindowShouldClose(window)) {

	}

	// Dispose
	glfwDestroyWindow(window);
	glfwTerminate();
}