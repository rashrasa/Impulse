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
            ${CMAKE_CURRENT_SOURCE_DIR}/glad
)

file(GLOB_RECURSE APPLICATION_SOURCES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/Graphics/*.cpp
)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/assets/test.vert ${CMAKE_CURRENT_BINARY_DIR}/data/assets/test.vert COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/assets/test.frag ${CMAKE_CURRENT_BINARY_DIR}/data/assets/test.frag COPYONLY)

target_sources(
    PhysicsSimulations PRIVATE glad/glad.c ${APPLICATION_SOURCES}
)