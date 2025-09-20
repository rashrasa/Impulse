#!usr/bin/bash

cmake -B build_mingw -G "MinGW Makefiles"
cmake --build build_mingw

read -p "

Press enter to continue"