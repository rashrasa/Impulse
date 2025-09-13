#!usr/bin/bash

cmake -S . -B build -G "MinGW Makefiles"
cmake -S . -G "MinGW Makefiles"
cmake --build .

read -p "

Press enter to continue"