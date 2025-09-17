#include <fstream>

#include "shader.h"

namespace PhysicsGraphics {
    ShaderProgram::ShaderProgram(std::string vertexShaderSourceFile, std::string fragmentShaderSourceFile) {
        this->vertexShaderSourceFile = vertexShaderSourceFile;
        this->fragmentShaderSourceFile = fragmentShaderSourceFile;
    }
    ShaderProgram::~ShaderProgram() {
        glDeleteShader(this->vertexShader);
        glDeleteShader(this->fragmentShader);
    }
    void ShaderProgram::initialize() {
        std::ifstream vertSourceFile(this->vertexShaderSourceFile);
        int vertLength;
        vertSourceFile.seekg(0, std::ios::end);
        vertLength = vertSourceFile.tellg();
        vertSourceFile.seekg(0, std::ios::beg);
        char* const vertexShaderSource = new char[vertLength];
        vertSourceFile.read(vertexShaderSource, vertLength);
        vertSourceFile.close();

        std::ifstream fragSourceFile(this->fragmentShaderSourceFile);
        int fragLength;
        fragSourceFile.seekg(0, std::ios::end);
        fragLength = fragSourceFile.tellg();
        fragSourceFile.seekg(0, std::ios::beg);
        char* const fragmentShaderSource = new char[vertLength];
        fragSourceFile.read(vertexShaderSource, vertLength);
        fragSourceFile.close();

        vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);

        fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);


        shaderProgram = glCreateProgram();

        glAttachShader(shaderProgram, vertexShader);
        glAttachShader(shaderProgram, fragmentShader);
        glLinkProgram(shaderProgram);
    }
    unsigned int* ShaderProgram::getGLProgram() {
        return &(this->shaderProgram);
    }
}