#define GLFW_INCLUDE_NONE
#include <iostream>
#include "pch.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

static void handle_error(int error, const char* description) {
	std::cerr << "Error: " << description << std::endl;
}

static void handle_key(GLFWwindow* window, int key, int scancode, int action, int mods) {

}

static void render(GLFWwindow* window, PhysicsEngine::World* world) {

}

int main() {
	// Initialize
	if (!glfwInit()) {
		throw "Could not initialize GLFW";
	}
	auto window = glfwCreateWindow(640, 480, "Physics Simulations", NULL, NULL);
	if (!window) {
		throw "Could not create window";
	}
	glfwMakeContextCurrent(window);
	gladLoadGL();
	glfwSetErrorCallback(handle_error);
	glfwSetKeyCallback(window, handle_key);
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);
	double start_time_seconds = glfwGetTime();

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
		render(window, &world);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// Dispose
	glfwDestroyWindow(window);
	glfwTerminate();
}