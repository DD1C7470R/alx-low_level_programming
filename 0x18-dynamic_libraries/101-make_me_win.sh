#!/bin/bash
gcc -shared -o 101-make_me_win.so -fPIC 101-make_me_win.c
export LD_PRELOAD=./101-make_me_win.o
