cmake_minimum_required(VERSION 3.10)
project(cpp_sdl_game_base)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake_modules/")

set(SDL2_PATH "${CMAKE_SOURCE_DIR}/external_libs/SDL2-2.30.0/x86_64-w64-mingw32")

set(SDL2_IMAGE_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/external_libs/SDL2_image-2.0.0/include")
set(SDL2_IMAGE_LIBRARY "${CMAKE_SOURCE_DIR}/external_libs/SDL2_image-2.0.0/lib/x64")


find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})


add_executable(cpp_sdl_game_base src/main.cpp
        include/view/sdl_window.h
        include/utils/config.h
)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY}  ${SDL2_IMAGE_LIBRARIES})