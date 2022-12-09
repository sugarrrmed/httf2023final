#!/bin/sh

g++ -std=gnu++17  -Wextra -O2 -DONLINE_JUDGE -D=LOCAL -Wl,-stack_size -Wl,0x11110000 httf/main.cpp -o main.out

./main.out

rm main.out
