#!/bin/bash
cp payload.so ./payload.so
rm 101-make_me_win.sh
LD_PRELOAD=./payload.so ./gm 9 8 10 24 75 9
