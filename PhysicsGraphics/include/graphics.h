#pragma once

#include "glad/glad.h"
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

#include <unordered_map>

#include "Window.h"
#include "Shader.h"
#include "World.h"

namespace PhysicsGraphics {
    class GraphicsEngine {
        // Declarations
    private:
        PhysicsGraphics::Window* mainWindow;
        PhysicsEngine::World* world;
        std::unordered_map<std::string, PhysicsGraphics::ShaderProgram*> shaderPrograms;
        unsigned int VAO;
        unsigned int VBO;
        unsigned int EBO;
        Eigen::Matrix4f view;
        Eigen::Matrix4f projection;

        // API
    public:
        GraphicsEngine(PhysicsEngine::World* world, PhysicsGraphics::Window* window);
        ~GraphicsEngine();
        void initialize();
        void startEventLoop(PhysicsGraphics::Window* window);

    private:
        void render();
    };
}
