#pragma once

#include "glad/glad.h"
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

#include <string>

namespace Impulse::Render {
    class ShaderProgram {
        // Declarations
    private:
        // Only using Vertex and Fragment shaders
        unsigned int vertexShader;
        unsigned int fragmentShader;
        unsigned int shaderProgram;

        std::string vertexShaderSourceFile;
        std::string fragmentShaderSourceFile;

        // API
    public:
        ShaderProgram(std::string vertexShaderSourceFile, std::string fragmentShaderSourceFile);
        ~ShaderProgram();
        void initialize();
        unsigned int getGLProgram();
    };
}