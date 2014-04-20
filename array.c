#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "limits.h"
#include "array.h"

void array__print(int array[], unsigned int size)
{
    unsigned int i = 0;

    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");
}

bool array__read_from_file(char * const filename, unsigned int array_size, int array[])
{
    FILE *input_file = NULL;
    char read_buffer[MAX_NUMBER_LENGTH + 1] = {0};
    int i = 0;

    input_file = fopen(filename, "r");

    if (NULL == input_file) {
        return false;
    }

    for (i = 0 ; NULL != fgets(read_buffer, MAX_NUMBER_LENGTH + 1, input_file) && i < array_size; i++) {
        /* TODO: atoi doesn't detect errors */
        array[i] = atoi(read_buffer);
    }

    if (i != array_size) {
        return false;
    }

    return true;
}
