# cub3DRay-Casting Game

### A simple 2D ray-casting engine built in C with MLX42, inspired by the rendering style of classic games like DOOM (1993) and Wolfenstein 3D. This project simulates a 3D perspective using a 2D map and allows real-time exploration of a maze-like environment.

### Features

Ray-casting rendering for a pseudo-3D effect

Smooth player movement with real-time interaction

320 rays & 60-degree field of view for immersive visuals

Efficient performance handling for large maps

Basic wall collision detection

### Requirements

* C compiler (GCC/Clang)

* MLX42 graphics library

* CMake (optional, for building)

### Installation & Compilation

* Clone the repository:

  - git clone <repo-url>
  - cd raycasting-game

* Install dependencies:

* Install MLX42 (if not installed)
  - git clone https://github.com/codam-coding-college/MLX42.git
  - cd MLX42 && cmake -B build && cmake --build build && cd ..

### Compile the project:

* make

### How to Play

  Move: Arrow keys

  Look around: Left/Right arrow keys

  Quit: ESC key

### Known Issues

  Performance may drop with very large maps

  Occasional rendering glitches with long rays

### Credits

Developed by https://github.com/Arti2001 and https://github.com/gosi-a , inspired by classic FPS games.
