add_executable(App Main.cpp)

target_link_libraries(
    App
    PRIVATE
        Impulse
        glfw
)

target_include_directories(
    App
        PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/include
            ${CMAKE_SOURCE_DIR}/eigen
            ${CMAKE_SOURCE_DIR}/Impulse/include
)