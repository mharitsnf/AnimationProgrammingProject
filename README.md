# Animation Programming

This is an implementation of the book "Hands-On C++ Game Animation Programming" by Gabor Szauer. This repository contains a few adjustments from the original implementation of the book:

1. Instead of using Win32 for displaying the window, this repository uses GLFW.
2. This repository uses CMake for building and packaging the application. By using CMake, this application should not be limited to Windows. In fact, this application is developed in a MacBook (Intel chipset).

The latest application is located in `out/build/AnimationProject`. You can running the application in MacBook by calling `./run.sh` in terminal.