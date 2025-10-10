#pragma once

#include "glad/glad.h"
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

#include <unordered_map>
#include <memory>

#include "Impulse/Render/Window.h"
#include "Impulse/Render/Shader.h"
#include "Impulse/Core/Core.h"

namespace Impulse::Render {
    class GraphicsEngine {
        // Declarations
    private:
        // Owned by main thread
        std::shared_ptr<Window> mainWindow;
        std::shared_ptr<Impulse::Core::World> world;

        std::unordered_map<std::string, std::shared_ptr<Impulse::Render::ShaderProgram>> shaderPrograms;
        unsigned int VAO;
        unsigned int VBO;
        unsigned int EBO;
        Eigen::Matrix4f view;
        Eigen::Matrix4f projection;

        // API
    public:
        GraphicsEngine(std::shared_ptr<Impulse::Core::World> world, std::shared_ptr<Impulse::Render::Window> window);
        ~GraphicsEngine();
        void initialize();
        void startEventLoop();

    private:
        void render();
    };
}
