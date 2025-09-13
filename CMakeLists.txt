cmake_minimum_required(VERSION 4.1)

project(PhysicsSimulator LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_C_STANDARD 23)

add_subdirectory(PhysicsEngine)
add_subdirectory(glfw)
add_subdirectory(PhysicsSimulations)
