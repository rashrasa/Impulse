#include "graphics.h"
#include "shader.h"
#include <iostream>
#include <filesystem>

static Eigen::IOFormat eigen_formatter(2, 0, " ", "\n", "|", "|", "", "", 32);

static float timed_float(float phase) {
    return ((int)(glfwGetTime() * 1000.0 - phase * 1000.0) % 1000) / (1000.0);
}

namespace PhysicsGraphics {
    GraphicsEngine::GraphicsEngine(PhysicsEngine::World* world, PhysicsGraphics::Window* window) {
        this->initialized = false;
        this->shaderPrograms.clear();
        this->world = world;
        this->mainWindow = window;
    }
    // May not be necessary
    GraphicsEngine::~GraphicsEngine() = default;
    void GraphicsEngine::initialize() {
        // TODO: Find a way to package shader with app
        this->shaderPrograms.insert(std::pair("test", new PhysicsGraphics::ShaderProgram("data/assets/test.vert", "data/assets/test.frag")));
        std::cout << "Created shader" << std::endl;

        for (std::pair<const std::string, PhysicsGraphics::ShaderProgram*> pair : this->shaderPrograms) {
            std::cout << "Reading in shader" << std::endl;
            (*pair.second).initialize();
        }
        std::cout << "Initialized shaders" << std::endl;

        glUseProgram(*((*this->shaderPrograms.at("test")).getGLProgram()));
        std::cout << "Set shader program" << std::endl;

        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);
        std::cout << "Bound Vertex array" << std::endl;

        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        std::cout << "Bound buffer" << std::endl;

        float* vertices = this->world->entities[0]->getVertices();
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);
        std::cout << "Set buffer data" << std::endl;

        glGenBuffers(1, &EBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

        unsigned int* indices = this->world->entities[0]->getIndices();
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_DYNAMIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        std::cout << "Initialized graphics engine" << std::endl;
    }
    void GraphicsEngine::render() {
        glBindVertexArray(VAO);
        glClearColor(
            timed_float(0.1),
            timed_float(0.4),
            timed_float(0.6),
            1.0f
        );
        glClear(GL_COLOR_BUFFER_BIT);
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
    }
    void GraphicsEngine::startEventLoop(PhysicsGraphics::Window* window) {
        double start_time_ms = glfwGetTime();
        unsigned int renders = 0;
        unsigned int steps = 0;
        const float RENDER_RATE = 60.0;
        const float SIMULATION_STEP_RATE = RENDER_RATE * 4.0;
        while (!glfwWindowShouldClose(window->getWindow())) {
            double current_time_seconds = glfwGetTime();

            while ((current_time_seconds - start_time_ms) / (1.0 / RENDER_RATE) > renders) {
                if (renders % 60 == 0)
                    std::cout << "\n" << (*this->world->entities[0]->getModel()).format(eigen_formatter) << "\n" << std::endl;
                render();
                glfwSwapBuffers(window->getWindow());
                renders++;
            }

            while ((current_time_seconds - start_time_ms) / (1.0 / SIMULATION_STEP_RATE) > steps) {
                //world->tick(1.0 / SIMULATION_STEP_RATE);
                steps++;
            }

            glfwPollEvents();
        }
    }
}