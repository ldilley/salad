#!/bin/sh
gcc -o test -L. -Iinclude -lsalad test.c
export LD_LIBRARY_PATH=`pwd`:${LD_LIBRARY_PATH}
