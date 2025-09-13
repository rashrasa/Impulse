add_executable(PhysicsSimulations PhysicsSimulations.cpp)

target_link_libraries(
    PhysicsSimulations
    PRIVATE
        PhysicsEngine
        glfw
)

target_include_directories(
    PhysicsSimulations
        PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/include
            ${CMAKE_CURRENT_SOURCE_DIR}/../eigen
            ${CMAKE_CURRENT_SOURCE_DIR}/../glfw
)