add_library(ImpulseRender STATIC)

file(GLOB_RECURSE APPLICATION_SOURCES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/*.cpp
)

target_sources(
    ImpulseRender PRIVATE glad/glad.c ${APPLICATION_SOURCES}
)

target_link_libraries(
    ImpulseRender
    PRIVATE
        ImpulseCore
        glfw
)

target_include_directories(
    ImpulseRender
        PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/include
            ${CMAKE_SOURCE_DIR}/eigen
)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/assets/main.vert ${CMAKE_BINARY_DIR}/data/assets/main.vert COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/assets/main.frag ${CMAKE_BINARY_DIR}/data/assets/main.frag COPYONLY)