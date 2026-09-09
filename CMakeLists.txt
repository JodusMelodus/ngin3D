cmake_minimum_required(VERSION 3.20)

project(PhysicsEngine
    VERSION 0.1
    LANGUAGES C
)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# --------------------------------------------------
# GLFW
# --------------------------------------------------

add_library(glfw SHARED IMPORTED)

set_target_properties(glfw PROPERTIES
    IMPORTED_IMPLIB
        "${CMAKE_CURRENT_SOURCE_DIR}/external/glfw/lib-mingw-w64/libglfw3dll.a"

    IMPORTED_LOCATION
        "${CMAKE_CURRENT_SOURCE_DIR}/external/glfw/lib-mingw-w64/glfw3.dll"

    INTERFACE_INCLUDE_DIRECTORIES
        "${CMAKE_CURRENT_SOURCE_DIR}/external/glfw/include"
)

# --------------------------------------------------
# OpenGL
# --------------------------------------------------

find_package(OpenGL REQUIRED)

# --------------------------------------------------
# GLAD
# --------------------------------------------------

add_library(glad STATIC
    src/glad.c
)

target_include_directories(glad PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# --------------------------------------------------
# Physics Engine
# --------------------------------------------------

add_executable(physics-engine
    src/main.c
)

target_include_directories(physics-engine PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(physics-engine PRIVATE
    glad
    glfw
    OpenGL::GL
)

add_custom_command(TARGET physics-engine POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_CURRENT_SOURCE_DIR}/external/glfw/lib-mingw-w64/glfw3.dll"
        "$<TARGET_FILE_DIR:physics-engine>"
)