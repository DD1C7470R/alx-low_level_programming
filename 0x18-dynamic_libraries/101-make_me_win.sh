#!/bin/bash
gcc -shared -fPIC -o 101-make_me_win.o 101-make_me_win.c
export LD_PRELOAD="./101-make_me_win.so"
