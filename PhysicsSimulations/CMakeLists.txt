add_executable(PhysicsSimulations Main.cpp)

target_link_libraries(
    PhysicsSimulations
    PRIVATE
        PhysicsEngine
        PhysicsGraphics
        glfw
)

target_include_directories(
    PhysicsSimulations
        PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/include
            ${CMAKE_SOURCE_DIR}/eigen
)