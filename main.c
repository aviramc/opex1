/* TODO: Use std types? */

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define LIST_SIZE (5)
#define MAX_NUMBER_LENGTH (5)

static void _print_array(int array[], unsigned int size);
static bool _get_array_from_file(char * const filename, int array[], unsigned int list_size);

static void _print_array(int array[], unsigned int size)
{
    unsigned int i = 0;

    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");
}

static bool _get_array_from_file(char * const filename, int array[], unsigned int list_size)
{
    FILE *input_file = NULL;
    char read_buffer[MAX_NUMBER_LENGTH] = {0};
    int i = 0;

    input_file = fopen(filename, "r");

    if (NULL == input_file) {
        return false;
    }

    for (i = 0 ; NULL != fgets(read_buffer, MAX_NUMBER_LENGTH + 1, input_file) && i < list_size; i++) {
        /* TODO: atoi doesn't detect errors */
        array[i] = atoi(read_buffer);
    }

    if (i != list_size) {
        return false;
    }

    return true;
}

int main(int argc, char * const argv[])
{
    int input_array[LIST_SIZE] = {0};
    int output_array[LIST_SIZE] = {0};
    int rc = -1;

    if (2 != argc) {
        printf("Usage: %s input_file\n", argv[0]);
        rc = -1;
        goto end;
    }

    if (!_get_array_from_file(argv[1], input_array, LIST_SIZE)) {
        printf("Error reading list from file\n");
        rc = -1;
        goto end;
    }

    _print_array(input_array, LIST_SIZE);
    
end:
    return rc;
}
