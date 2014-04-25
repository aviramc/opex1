/* array.h - a module for operations on an array of integers.
 */

#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <stdbool.h>

/* An expression that is true when the array is empty, according to the array's start index and its size. */
#define ARRAY_EMPTY(start_index, size) ((start_index) >= (size))

void array__print(int array[], unsigned int size);

/* array__read_from_file
   Read an array of size array_size from the file named filename into the given array.
   The file must include integers separated by newlines.
   The functions returns true on success and false on failures.
 */
bool array__read_from_file(char * const filename, unsigned int array_size, int array[]);

/* array__read_from_file
   Find the index of the largest member of the array, starting from start_index
   up to end_index (including both indexes>
 */
unsigned int array__find_max_index(int array[], unsigned int start_index, unsigned int end_index);

/* array__max_to_first
   Puts the largest member of the array (from starting_index to end_index including both
   indexes), and puts it in start_index. The member in start_index will be swapped with
   the largest member.
 */
void array__max_to_first(int array[], unsigned int start_index, unsigned int end_index);

/* Functions for resetting and getting the amount of comparisons for the array__find_max_index function.
   array__reset_comparisons - sets the comparisons counter to zero, so this should be called on initialization.
   array__get_comparisons - retrieves the comparisons counter.
 */
void array__reset_comparisons();
unsigned int array__get_comparisons();

#endif /* __ARRAY_H__ */
