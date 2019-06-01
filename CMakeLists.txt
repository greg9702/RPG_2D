cmake_minimum_required(VERSION 3.10)
project(RPG)

set(CMAKE_CXX_STANDARD 17)

include_directories("include" "SFML-2.5.1/include")
link_directories("SFML-2.5.1/lib")

file(GLOB SOURCES "src/*.cpp")
add_executable(game ${SOURCES} )

target_link_libraries (game sfml-graphics sfml-window sfml-system )