#version 460 core

layout(location = 0) in vec3 aPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec4 fragPos;

void main() {
    fragPos = projection * view * model * vec4(aPos, 1.0);
    gl_Position = fragPos;
}