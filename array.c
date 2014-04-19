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

unsigned int array__find_max_index(int array[], unsigned int start_index, unsigned int end_index)
{
    int current_max_index = start_index;
    unsigned int i = start_index;

    for (i = start_index; i <= end_index; i++) {
        if (array[i] > array[current_max_index]) {
            current_max_index = i;
        }
    }

    return current_max_index;
}

void array__max_to_first(int array[], unsigned int start_index, unsigned int end_index)
{
    int temp = 0;
    int max_index = array__find_max_index(array, start_index, end_index);

    temp = array[max_index];
    array[max_index] = array[0];
    array[0] = temp;
}
