cmake_minimum_required(VERSION 3.0.0)
project(galaxy VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_LIBRARY_PATH ${CMAKE_SOURCE_DIR}/Lib)

include(CTest)
enable_testing()

include_directories(
    Include
    Models
    Models/Geometry
    UI
    UI/Events
    UI/Text
    UI/Structures)

add_executable(galaxy WIN32 Main.cpp)

find_library(SDL_LIBRARY
    NAMES SDL2 SDL2main
    HINTS "${CMAKE_PREFIX_PATH}")
find_library(SDL_TTF_LIBRARY
    NAMES SDL2_ttf
    HINTS "${CMAKE_PREFIX_PATH}")
target_link_libraries(galaxy ${SDL_LIBRARY} ${SDL_TTF_LIBRARY})

add_subdirectory(UI)
add_subdirectory(Models)

add_custom_target(SDL_BINARIES
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_LIBRARY_PATH}/libfreetype-6.dll ${CMAKE_BINARY_DIR}/Debug/libfreetype-6.dll
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_LIBRARY_PATH}/SDL2_ttf.dll      ${CMAKE_BINARY_DIR}/Debug/SDL2_ttf.dll
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_LIBRARY_PATH}/SDL2.dll          ${CMAKE_BINARY_DIR}/Debug/SDL2.dll
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_LIBRARY_PATH}/zlib1.dll         ${CMAKE_BINARY_DIR}/Debug/zlib1.dll)
add_dependencies(galaxy SDL_BINARIES)

add_custom_target(ASSETS
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/Assets/Fonts/Courier.ttf ${CMAKE_BINARY_DIR}/Assets/Fonts/Courier.ttf
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/Assets/Images/icon.bmp   ${CMAKE_BINARY_DIR}/Assets/Images/icon.bmp)
add_dependencies(galaxy ASSETS)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

include(CPack)
