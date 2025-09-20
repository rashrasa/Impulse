add_library(PhysicsGraphics STATIC)

file(GLOB_RECURSE APPLICATION_SOURCES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/*.cpp
)

target_sources(
    PhysicsGraphics PRIVATE glad/glad.c ${APPLICATION_SOURCES}
)

target_link_libraries(
    PhysicsGraphics
    PRIVATE
        PhysicsEngine
)

target_include_directories(
    PhysicsGraphics
        PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/include
            ${CMAKE_SOURCE_DIR}/eigen
            ${CMAKE_SOURCE_DIR}/glfw/include
            ${CMAKE_CURRENT_SOURCE_DIR}/glad
)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/assets/main.vert ${CMAKE_BINARY_DIR}/data/assets/main.vert COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/assets/main.frag ${CMAKE_BINARY_DIR}/data/assets/main.frag COPYONLY)