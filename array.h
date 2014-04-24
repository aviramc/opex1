#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <stdbool.h>

#define ARRAY_EMPTY(start_index, size) ((start_index) >= (size))

void array__print(int array[], unsigned int size);
bool array__read_from_file(char * const filename, unsigned int array_size, int array[]);
unsigned int array__find_max(int array[], unsigned int start_index, unsigned int end_index);
void array__max_to_first(int array[], unsigned int start_index, unsigned int end_index);

#endif /* __ARRAY_H__ */
