add_library(ImpulsePhysics STATIC)

file(GLOB_RECURSE ENGINE_SOURCES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/*.cpp
)

target_sources(ImpulsePhysics PRIVATE ${ENGINE_SOURCES})

target_link_libraries(
    ImpulsePhysics
    PRIVATE
        ImpulseCore
)

target_include_directories(
    ImpulsePhysics
        PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/include
            ${CMAKE_SOURCE_DIR}/eigen
)