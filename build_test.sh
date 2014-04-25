#!/bin/bash

# TODO: Makefile, gcc flags.
gcc -g number.c array.c test_array.c -o test_array

gcc -g number.c test_number.c -o test_number
