#include "graphics.h"
#include "shader.h"
#include <iostream>
#include <filesystem>

static Eigen::IOFormat eigen_formatter(4, 0, " ", "\n", "|", "|", "", "", 32);

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

        for (auto pair : this->shaderPrograms) {
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

        glBufferData(GL_ARRAY_BUFFER, this->world->entities[0]->getNumVertices(), this->world->entities[0]->getVertices(), GL_DYNAMIC_DRAW);

        std::cout << "Set buffer data" << std::endl;

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

        glDrawArrays(GL_TRIANGLES, 0, 3);
    }
    void GraphicsEngine::startEventLoop(PhysicsGraphics::Window* window) {
        double start_time_ms = glfwGetTime();
        uint64_t renders = 0;
        uint64_t steps = 0;
        const float RENDER_RATE = 60.0;
        const float SIMULATION_STEP_RATE = RENDER_RATE * 4.0;
        while (!glfwWindowShouldClose(window->getWindow())) {
            double current_time_seconds = glfwGetTime();

            while ((current_time_seconds - start_time_ms) / (1.0 / RENDER_RATE) > renders) {
                if (renders % 60 == 0)
                    std::cout << "\n" << (this->world->entities[0]->model).format(eigen_formatter) << "\n" << std::endl;
                render();
                glfwSwapBuffers(window->getWindow());
                renders++;
            }

            while ((current_time_seconds - start_time_ms) / (1.0 / SIMULATION_STEP_RATE) > steps) {
                world->tick(1.0 / SIMULATION_STEP_RATE);
                steps++;
            }

            glfwPollEvents();
        }
    }
}