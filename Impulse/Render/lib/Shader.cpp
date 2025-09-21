#include <fstream>
#include <iostream>

#include "Impulse/Render/Shader.h"

namespace Impulse::Render {
    ShaderProgram::ShaderProgram(std::string vertexShaderSourceFile, std::string fragmentShaderSourceFile) {
        this->vertexShaderSourceFile = vertexShaderSourceFile;
        this->fragmentShaderSourceFile = fragmentShaderSourceFile;
    }
    ShaderProgram::~ShaderProgram() {
        glDeleteShader(this->vertexShader);
        glDeleteShader(this->fragmentShader);
    }
    void ShaderProgram::initialize() {
        std::cout << "Initializing shader" << std::endl;
        std::ifstream vertSourceFile(this->vertexShaderSourceFile);
        int vertLength;
        vertSourceFile.seekg(0, std::ios::end);
        vertLength = vertSourceFile.tellg();
        if (vertLength == -1) {
            throw std::runtime_error("Could not open " + this->vertexShaderSourceFile);
        }
        vertSourceFile.seekg(0, std::ios::beg);
        char* const vertexShaderSource = new char[vertLength];
        vertSourceFile.read(vertexShaderSource, vertLength);
        vertSourceFile.close();
        std::cout << "Read vertex shader file" << std::endl;

        std::ifstream fragSourceFile(this->fragmentShaderSourceFile);
        int fragLength;
        fragSourceFile.seekg(0, std::ios::end);
        fragLength = fragSourceFile.tellg();
        if (fragLength == -1) {
            throw std::runtime_error("Could not open " + this->vertexShaderSourceFile);
        }
        fragSourceFile.seekg(0, std::ios::beg);
        char* const fragmentShaderSource = new char[fragLength];
        fragSourceFile.read(fragmentShaderSource, fragLength);
        fragSourceFile.close();
        std::cout << "Read fragment shader file" << std::endl;

        vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
        std::cout << "Set vertex shader" << std::endl;

        fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
        std::cout << "Set fragment shader" << std::endl;

        shaderProgram = glCreateProgram();
        std::cout << "Created shader program" << std::endl;

        glAttachShader(shaderProgram, vertexShader);
        glAttachShader(shaderProgram, fragmentShader);
        glLinkProgram(shaderProgram);

        GLint success;
        glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
        if (!success) {
            char error[512];
            glGetProgramInfoLog(shaderProgram, 512, nullptr, error);
            std::cout << "Shader Compilation Error: " << std::endl;
            throw std::runtime_error(error);
        }
    }
    unsigned int* ShaderProgram::getGLProgram() {
        return &(this->shaderProgram);
    }
}