#!/bin/bash

# TODO: Makefile, gcc flags.
gcc -g -Wall -std=gnu99 number.c array.c test_array.c -o test_array

gcc -g -Wall -std=gnu99 number.c test_number.c -o test_number
