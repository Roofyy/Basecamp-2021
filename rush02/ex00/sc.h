#!/bin/bash
gcc rush00.c -o r0.out
gcc functions.c rush01.c -o r1.out
gcc functions.c rush02.c -o r2.out
gcc functions.c rush03.c -o r3.out
gcc functions.c rush04.c -o r4.out
gcc main.c 

./r0.out | ./a.out 
./r1.out | ./a.out 
./r2.out | ./a.out 
./r3.out | ./a.out 
./r4.out | ./a.out 
