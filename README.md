# iv

`iv` is a C-based application built with [SDL2](https://libsdl.org/) that reads and displays PPM images.

This was created as a learning exercise to better understand SDL2 and image rendering at a basic level.

## Requirements

### SDL2

```
pacman -S sdl2
```

## Installation

Clone the repository:

```
git clone https://github.com/moonflower9/iv.git
cd iv
```

Compile the program (using pkg-config to supply the correct flags):
```
gcc iv.c -o iv $(pkg-config --cflags --libs sdl2)
```

Run the program:
```
./iv path/to/image.ppm
```

## Notes

- Heavily inspired by [this](https://www.youtube.com/watch?v=sItRLFjbqvo) project by Daniel Hirsch, mainly redeveloped by myself to build understanding with SDL2.

## License

This project is licensed under the MIT License.
