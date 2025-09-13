cmake_minimum_required(VERSION 4.1)

project(PhysicsSimulator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(PhysicsSimulations)
add_subdirectory(PhysicsEngine)
add_subdirectory(glfw)
