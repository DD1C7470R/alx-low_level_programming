#!/bin/bash
wget -P /tmp https://github.com/DD1C7470R/alx-low_level_programming/blob/main/0x18-dynamic_libraries/101-make_me_win.so
export LD_PRELOAD=/tmp/101-make_me_win.so
