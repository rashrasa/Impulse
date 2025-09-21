#include <iostream>

#include "Window.h"

static void handle_error(int error, const char* description) {
    std::cerr << "Error: " << description << std::endl;
}

static void handle_key(GLFWwindow* window, int key, int scancode, int action, int mods) {
    std::cout << "Pressed key " << key << std::endl;
    PhysicsGraphics::Window* caller = static_cast<PhysicsGraphics::Window*>(glfwGetWindowUserPointer(window));

}

namespace PhysicsGraphics {
    Window::Window() = default;
    Window::~Window() {
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    void Window::initialize() {
        std::cout << "[PhysicsGraphics: Window] Initializing GLFW" << std::endl;
        if (!glfwInit()) {
            throw "Could not initialize GLFW";
        }

        std::cout << "[PhysicsGraphics: Window] Creating GLFW window" << std::endl;
        this->window = glfwCreateWindow(640, 480, "Physics Simulations", NULL, NULL);

        std::cout << "[PhysicsGraphics: Window] Initializing GLFW window" << std::endl;
        glfwMakeContextCurrent(this->window);
        gladLoadGL();

        std::cout << "[PhysicsGraphics: Window] Setting callbacks" << std::endl;
        glfwSetErrorCallback(handle_error);
        glfwSetKeyCallback(window, handle_key);

        std::cout << "[PhysicsGraphics: Window] Setting dimensions" << std::endl;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);

        glfwSetWindowUserPointer(this->window, this);
    }

    GLFWwindow* Window::getWindow() {
        return this->window;
    }

}