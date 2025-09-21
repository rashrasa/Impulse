#pragma once

#include "glad/glad.h"
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

namespace PhysicsGraphics {
    class Window {
        // Declarations
    private:
        GLFWwindow* window = nullptr;
        bool initialized = false;
        bool visible = false;

        // API
        // TODO: Implement ability to attach keyboard event callbacks 
    public:
        Window();
        ~Window();
        void initialize();
        GLFWwindow* getWindow();
    };
}
