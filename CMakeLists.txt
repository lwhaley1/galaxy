cmake_minimum_required(VERSION 3.0.0)
project(galaxy VERSION 1.0)

include(CTest)
enable_testing()

include_directories(lib/SDL/include UI)

add_executable(galaxy Main.cpp)

add_subdirectory(lib/SDL)
add_subdirectory(UI)
target_link_libraries(galaxy SDL2)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

include(CPack)
