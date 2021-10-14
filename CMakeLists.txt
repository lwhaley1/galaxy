cmake_minimum_required(VERSION 3.0.0)
project(galaxy VERSION 1.0)
set(CMAKE_CXX_STANDARD 17)

include(CTest)
enable_testing()

include_directories(lib/SDL/include UI UI/Events)

if (WIN32)
    add_executable(galaxy WIN32 Main.cpp)
endif (WIN32)
if (UNIX)
    add_executable(galaxy Main.cpp)
endif (UNIX)

add_subdirectory(lib/SDL)
add_subdirectory(UI)
target_link_libraries(galaxy SDL2-static)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

include(CPack)
