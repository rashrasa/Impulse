#include "graphics.h"
#include "shader.h"

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
        PhysicsGraphics::ShaderProgram mainShaderProgram("assets\\test.vert", "assets\\test.frag");
        this->shaderPrograms["test"] = &mainShaderProgram;

        for (auto pair : this->shaderPrograms) {
            (*pair.second).initialize();
        }

        // Triangles
        float vertices[] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f,  0.5f, 0.0f
        };

        glUseProgram(*((*this->shaderPrograms["test"]).getGLProgram()));

        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);

        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
    }
    void GraphicsEngine::render() {
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
    void GraphicsEngine::startEventLoop(PhysicsGraphics::Window* window) {
        double start_time_ms = glfwGetTime();
        uint64_t renders = 0;
        uint64_t steps = 0;
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
                world->tick(1.0 / SIMULATION_STEP_RATE);
                steps++;
            }
            glfwPollEvents();
        }
    }
}