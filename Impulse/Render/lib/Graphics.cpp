#include <iostream>
#include <filesystem>
#include <cmath>

#include "Impulse/Render/Graphics.h"
#include "Impulse/Render/Shader.h"

static Eigen::IOFormat eigen_formatter(10, 0, " ", "\n", "|", "|", "", "", 32);

static float timed_float(float phase) {
    return ((int)(glfwGetTime() * 1000.0 - phase * 1000.0) % 1000) / (1000.0);
}

namespace Impulse::Render {
    GraphicsEngine::GraphicsEngine(Impulse::Core::World* world, Impulse::Render::Window* window) {
        this->shaderPrograms.clear();
        this->world = world;
        this->mainWindow = window;

        // TODO: Fix and implement math abstraction
        float aspectRatio = 16.0 / 9.0;
        float hFov = 3.1415926 * (89.999 / 180);
        float far = 100.0;
        float near = 1.0;

        this->view <<
            1.0f, 0.0f, 0.0f, 5.0f,
            0.0f, 1.0f, 0.0f, 5.0f,
            0.0f, 0.0f, 1.0f, 5.0f,
            0.0f, 0.0f, 0.0f, 1.0f;

        this->projection <<
            1.0 / (aspectRatio * std::tan(hFov / 2.0)), 0, 0, 0,
            0, 1.0 / (std::tan(hFov / 2.0)), 0, 0,
            0, 0, -(far + near) / (far - near), -(2 * far * near) / (far - near),
            0, 0, -1, 0;
    }
    // May not be necessary
    GraphicsEngine::~GraphicsEngine() = default;
    void GraphicsEngine::initialize() {
        // TODO: Find a way to package shader with app
        this->shaderPrograms.insert(std::pair("test", new Impulse::Render::ShaderProgram("../data/assets/main.vert", "../data/assets/main.frag")));
        std::cout << "Created shader" << std::endl;

        for (std::pair<const std::string, Impulse::Render::ShaderProgram*> pair : this->shaderPrograms) {
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
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices) * 24, vertices, GL_DYNAMIC_DRAW);
        std::cout << "Set buffer data" << std::endl;

        glGenBuffers(1, &EBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

        unsigned int* indices = this->world->entities[0]->getIndices();
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices) * 36, indices, GL_DYNAMIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        int modelLoc = glGetUniformLocation(*(*this->shaderPrograms["test"]).getGLProgram(), "model");
        if (modelLoc == -1) throw std::runtime_error("Could not get model uniform");
        float* model = (*this->world->entities[0]->getModel()).data();
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, model);

        int viewLoc = glGetUniformLocation(*(*this->shaderPrograms["test"]).getGLProgram(), "view");
        if (modelLoc == -1) throw std::runtime_error("Could not get view uniform");
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, this->view.data());

        int projectionLoc = glGetUniformLocation(*(*this->shaderPrograms["test"]).getGLProgram(), "projection");
        if (modelLoc == -1) throw std::runtime_error("Could not get projection uniform");
        glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, this->projection.data());

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
    void GraphicsEngine::startEventLoop(Impulse::Render::Window* window) {
        double start_time_ms = glfwGetTime();
        unsigned int renders = 0;
        unsigned int steps = 0;
        const float RENDER_RATE = 60.0;
        const float SIMULATION_STEP_RATE = RENDER_RATE * 4.0;
        while (!glfwWindowShouldClose(window->getWindow())) {
            double current_time_seconds = glfwGetTime();

            while ((current_time_seconds - start_time_ms) / (1.0 / RENDER_RATE) > renders) {
                render();
                glfwSwapBuffers(window->getWindow());
                renders++;
            }

            while ((current_time_seconds - start_time_ms) / (1.0 / SIMULATION_STEP_RATE) > steps) {
                world->tick(1000.0 / SIMULATION_STEP_RATE);
                steps++;
            }

            glfwPollEvents();
        }
    }
}