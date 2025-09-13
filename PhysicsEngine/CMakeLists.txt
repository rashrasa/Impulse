add_library(PhysicsEngine STATIC)

target_sources(
    PhysicsEngine
        PRIVATE
            lib/pch.cpp
)

target_include_directories(
    PhysicsEngine
        PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/include
            ${CMAKE_CURRENT_SOURCE_DIR}/../eigen
)