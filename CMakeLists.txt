cmake_minimum_required(VERSION 4.1)

project(ImpulseApp LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_subdirectory(glfw)
add_subdirectory(Impulse)
add_subdirectory(App)