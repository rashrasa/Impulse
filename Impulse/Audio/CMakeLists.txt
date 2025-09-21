add_library(ImpulseAudio STATIC)

file(GLOB_RECURSE ENGINE_SOURCES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/*.cpp
)

target_sources(ImpulseAudio PRIVATE ${ENGINE_SOURCES})

target_link_libraries(
    ImpulseAudio
    PRIVATE
        ImpulseCore
)

target_include_directories(
    ImpulseAudio
        PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/include
            ${CMAKE_SOURCE_DIR}/eigen
)