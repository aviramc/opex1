Exercise 14 - sort an array (descending) by dividing it into sub-arrays and finding the
maximum of each subarray.

Constants
=========
 * The number of members in the array - ARRAY_SIZE in main.c . Defined to 256.
 * The number of sub-arrays - SUB_ARRAYS in subarray.h .

Compiling (building)
====================
 * After setting the constants as you wish, you can compile by running ./build.sh .
   The executable's name would be ex14.
 * In order to compile the tests, run build_test.sh , which will create the executables
   test_array and test_number.

Running
=======
 * The usage of the program is as follows:

./ex14 input_file

 * input_file - is the filename of a file containing the array. The file must contain
   decimal integers, a member per line, with no omre than 6 digits.
   If the file doesn't exist, or if one of the lines doesn't contain a number, an error
   would occur and the program will not continue.

Output
======
 * The output of the program would be the input array, the ordered array and the number
   of comparisons that were made.

