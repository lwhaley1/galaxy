cmake_minimum_required(VERSION 3.0.0)
project(galaxy VERSION 1.0)
set(CMAKE_CXX_STANDARD 17)

include(CTest)
enable_testing()

include_directories(
    include/SDL
    UI 
    UI/Events)

add_subdirectory(lib/SDL2)
add_subdirectory(lib/SDL2_ttf)

if (WIN32)
    add_executable(galaxy WIN32 Main.cpp)
endif (WIN32)
if (UNIX)
    add_executable(galaxy Main.cpp)
endif (UNIX)

target_link_libraries(galaxy SDL2 SDL2_ttf)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

include(CPack)
