#include "glad/glad.h"
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

#include <iostream>
#include "pch.h"

static void handle_error(int error, const char* description) {
	std::cerr << "Error: " << description << std::endl;
}

static void handle_key(GLFWwindow* window, int key, int scancode, int action, int mods) {
	std::cout << "Pressed key " << key << std::endl;
}

static float timed_float(float phase) {
	return ((int)(glfwGetTime() * 1000.0 - phase * 1000.0) % 1000) / (1000.0);
}

static void render(GLFWwindow* window, PhysicsEngine::World* world) {
	glClearColor(
		timed_float(0.1),
		timed_float(0.9),
		timed_float(0.6),
		1.0f
	);
	glClear(GL_COLOR_BUFFER_BIT);
}

static void update(PhysicsEngine::World* world, float dt) {
	world->tick(dt);
}

static void compile_shaders() {

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
	double start_time_ms = glfwGetTime();
	uint64_t renders = 0;
	uint64_t steps = 0;
	const float RENDER_RATE = 60.0;
	const float SIMULATION_STEP_RATE = RENDER_RATE * 4.0;

	while (!glfwWindowShouldClose(window)) {
		double current_time_seconds = glfwGetTime();

		while ((current_time_seconds - start_time_ms) / (1.0 / RENDER_RATE) > renders) {
			render(window, &world);
			glfwSwapBuffers(window);
			renders++;
		}

		while ((current_time_seconds - start_time_ms) / (1.0 / SIMULATION_STEP_RATE) > steps) {
			update(&world, 1.0 / SIMULATION_STEP_RATE);
			steps++;
		}
		glfwPollEvents();
	}

	// Dispose
	glfwDestroyWindow(window);
	glfwTerminate();
}