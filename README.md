# RPG-game

Role play game project. <br>
Game made using SFML. <br>
### Requirements
- CMake
- g++
- [SFML](https://www.sfml-dev.org/download/sfml/2.5.1/)

### Map

Map is stored in file game_files/map_template.txt as two dimension array.

### GUI

GUI can be called as "MVP" and all graphics are made by me :D <br>
It is just made as simple as possible, mainly for testing and developing purposes.

![Alt Text](https://i.imgur.com/UfD55iU.png)

### How to play

Use __W__, __S__, __A__, __D__ to move around. <br>
When you step on squre occupied by an enemy, the fight starts. <br>
Follow the instructions.

### How to build

Go to [SFML](https://www.sfml-dev.org/download/sfml/2.5.1/). <br>
Download files and extract to project directory. <br>
Then: <br>
```
mkdir build
cd build
cmake ..
make
```

> A lot of things left to do here
