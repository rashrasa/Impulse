add_library(Impulse INTERFACE)

add_subdirectory(Audio)
add_subdirectory(Core)
add_subdirectory(Physics)
add_subdirectory(Render)

target_link_libraries(Impulse INTERFACE
    ImpulseCore
    ImpulsePhysics
    ImpulseAudio
    ImpulseRender
)

target_include_directories(
    ImpulseCore
        PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/include
)