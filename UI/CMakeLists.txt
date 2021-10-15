cmake_minimum_required(VERSION 3.0.0)

add_subdirectory(Events)
add_subdirectory(Text)
add_subdirectory(Structures)

target_sources(galaxy PRIVATE UI/Window.cpp UI/Renderer.cpp)
