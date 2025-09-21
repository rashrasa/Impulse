add_library(ImpulseCore STATIC)

file(GLOB_RECURSE ENGINE_SOURCES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/*.cpp
)

target_sources(ImpulseCore PRIVATE ${ENGINE_SOURCES})

target_include_directories(
    ImpulseCore
        PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/include
            ${CMAKE_SOURCE_DIR}/eigen
)