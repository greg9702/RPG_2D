cmake_minimum_required(VERSION 3.10)
project(RPG)

set(CMAKE_CXX_STANDARD 17)
find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)
find_package (OpenGL)
if(SFML_FOUND)

    message(STATUS "SFML_INCLUDE_DIRS: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")

    include_directories(${SFML_INCLUDE_DIRS})

endif()
#SET(GCC_COMPILE_FLAGS "-lpthread -lncurses")
#add_definitions(${GCC_COMPILE_FLAGS})

#find_package(Curses REQUIRED)
#include_directories(${CURSES_INCLUDE_DIR})
#target_link_libraries(snake ${CURSES_LIBRARIES})

SET(GCC_COMPILE_FLAGS "-g -lsfml-window -lsfml-system -lGLU -lGL")


include_directories(include)
file(GLOB SOURCES "src/*.cpp" "include/*.h")
add_executable(game ${SOURCES})
target_link_libraries (game sfml-graphics sfml-window sfml-system -lsfml-system -lGLU -lGL)

