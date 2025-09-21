#version 460 core

in vec4 fragPos;
out vec4 FragColor;

void main() {
    FragColor = vec4(fragPos.x, fragPos.y, fragPos.z, 1.0);
}