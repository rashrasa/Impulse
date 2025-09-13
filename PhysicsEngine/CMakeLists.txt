add_library(PhysicsEngine STATIC)

file(GLOB_RECURSE ENGINE_SOURCES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/*.cpp
)

target_sources(PhysicsEngine PRIVATE ${ENGINE_SOURCES})

target_include_directories(
    PhysicsEngine
        PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/include
            ${CMAKE_CURRENT_SOURCE_DIR}/../eigen
)