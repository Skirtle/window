cmake_minimum_required(VERSION 3.10)
project(OpenGLStarter)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(external/glfw)
add_library(glad external/glad/src/glad.c)
target_include_directories(glad PUBLIC external/glad/include)

add_executable(OpenGLStarter src/main.cpp)

target_link_libraries(OpenGLStarter glfw glad)
if (WIN32)
    target_link_libraries(OpenGLStarter opengl32)
elseif(APPLE)
    find_library(OpenGL_LIB OpenGL)
    target_link_libraries(OpenGLStarter ${OpenGL_LIB})
else()
    target_link_libraries(OpenGLStarter GL)
endif()
