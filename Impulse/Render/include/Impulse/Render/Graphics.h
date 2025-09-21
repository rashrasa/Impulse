#pragma once

#include "glad/glad.h"
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

#include <unordered_map>

#include "Impulse/Render/Window.h"
#include "Impulse/Render/Shader.h"
#include "Impulse/Core/Core.h"

namespace impulse::render {
    class GraphicsEngine {
        // Declarations
    private:
        Window* mainWindow;
        impulse::core::World* world;
        std::unordered_map<std::string, impulse::render::ShaderProgram*> shaderPrograms;
        unsigned int VAO;
        unsigned int VBO;
        unsigned int EBO;
        Eigen::Matrix4f view;
        Eigen::Matrix4f projection;

        // API
    public:
        GraphicsEngine(impulse::core::World* world, impulse::render::Window* window);
        ~GraphicsEngine();
        void initialize();
        void startEventLoop(impulse::render::Window* window);

    private:
        void render();
    };
}
