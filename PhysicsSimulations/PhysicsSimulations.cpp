#include "glad/glad.h"
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

#include <iostream>
#include "pch.h"

#include <fstream>

// TODO: Organize variables properly
unsigned int fragmentShader;
unsigned int vertexShader;
unsigned int shaderProgram;
GLFWwindow* window;
unsigned int VAO;
unsigned int VBO;

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
	glUseProgram(shaderProgram);
	glBindVertexArray(VAO);
	glClearColor(
		timed_float(0.1),
		timed_float(0.9),
		timed_float(0.6),
		1.0f
	);
	glClear(GL_COLOR_BUFFER_BIT);

	glDrawArrays(GL_TRIANGLES, 0, 3);
}

static void update(PhysicsEngine::World* world, float dt) {
	world->tick(dt);
}

static void compile_and_set_shaders() {
	// TODO: Find way to package app with shader files

	std::ifstream vertSourceFile("assets\\test.vert");
	int vertLength;
	vertSourceFile.seekg(0, std::ios::end);
	vertLength = vertSourceFile.tellg();
	vertSourceFile.seekg(0, std::ios::beg);
	char* const vertexShaderSource = new char[vertLength];
	vertSourceFile.read(vertexShaderSource, vertLength);
	vertSourceFile.close();

	std::ifstream fragSourceFile("assets\\test.frag");
	int fragLength;
	fragSourceFile.seekg(0, std::ios::end);
	fragLength = fragSourceFile.tellg();
	fragSourceFile.seekg(0, std::ios::beg);
	char* const fragmentShaderSource = new char[vertLength];
	fragSourceFile.read(vertexShaderSource, vertLength);
	fragSourceFile.close();

	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);

	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);


	shaderProgram = glCreateProgram();

	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	glUseProgram(shaderProgram);
}

static void dispose() {
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	glfwDestroyWindow(window);
	glfwTerminate();
}

int main() {
	// Initialize
	if (!glfwInit()) {
		throw "Could not initialize GLFW";
	}
	window = glfwCreateWindow(640, 480, "Physics Simulations", NULL, NULL);
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

	// Triangles
	float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f,  0.5f, 0.0f
	};


	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);

	compile_and_set_shaders();

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);


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

	dispose();
}