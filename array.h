#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <stdbool.h>

void array__print(int array[], unsigned int size);
bool array__read_from_file(char * const filename, unsigned int array_size, int array[]);

#endif /* __ARRAY_H__ */
