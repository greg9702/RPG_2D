cmake_minimum_required(VERSION 3.10)
project(RPG)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

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

SET(GCC_COMPILE_FLAGS "-g -lsfml-window -lsfml-system -lGLU -lGL")


#add_executable(game src/main.cpp include/Game.h include/Map.h include/Player.h include/Object.h include/Enemy.h src/Game.cpp src/Map.cpp src/Player.cpp src/Object.cpp src/Enemy.cpp include/Fight.h src/Fight.cpp src/Character.cpp include/Character.h include/Item.h include/Weapon.h src/Weapon.cpp src/Item.cpp src/Armour.cpp include/Armour.h src/Window.cpp include/Window.h)

add_executable(game src/main.cpp include/Game.h include/Map.h include/Player.h include/Object.h include/Enemy.h src/Game.cpp src/Map.cpp src/Player.cpp src/Object.cpp src/Enemy.cpp src/Character.cpp include/Character.h src/Game_Window.cpp include/Game_Window.h include/Game.h include/Map.h include/Object.h include/Player.h include/Character.h include/Enemy.h src/Game.cpp src/Map.cpp src/main.cpp src/Character.cpp src/Enemy.cpp src/Object.cpp src/Player.cpp src/Game_Window.cpp include/Game_Window.h)
target_link_libraries (game sfml-graphics sfml-window sfml-system -lsfml-system -lGLU -lGL)

#target_link_libraries(snake ${CURSES_LIBRARIES})
