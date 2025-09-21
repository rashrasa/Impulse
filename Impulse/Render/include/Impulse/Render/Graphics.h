#pragma once

#include "glad/glad.h"
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

#include <unordered_map>

#include "Impulse/Render/Window.h"
#include "Impulse/Render/Shader.h"
#include "Impulse/Core/Core.h"

namespace Impulse::Render {
    class GraphicsEngine {
        // Declarations
    private:
        Window* mainWindow;
        Impulse::Core::World* world;
        std::unordered_map<std::string, Impulse::Render::ShaderProgram*> shaderPrograms;
        unsigned int VAO;
        unsigned int VBO;
        unsigned int EBO;
        Eigen::Matrix4f view;
        Eigen::Matrix4f projection;

        // API
    public:
        GraphicsEngine(Impulse::Core::World* world, Impulse::Render::Window* window);
        ~GraphicsEngine();
        void initialize();
        void startEventLoop(Impulse::Render::Window* window);

    private:
        void render();
    };
}
