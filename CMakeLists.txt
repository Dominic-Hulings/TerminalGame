cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SRC_FILES src/*.cpp)
file(GLOB_RECURSE INCLUDE_FILES includes/*.h)

include_directories(includes)

project(game VERSION 1.0)

add_executable(game.o ${SRC_FILES} ${INCLUDE_FILES})
target_link_libraries(game.o PUBLIC -L/usr/local/lib -lftxui-component -lftxui-dom -lftxui-screen)
target_compile_options(game.o PUBLIC -I/usr/local/include)