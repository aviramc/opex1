/* TODO: Use std types? */

#include <stdio.h>

#include "limits.h"
#include "array.h"

#define LIST_SIZE (5)

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

    if (!array__read_from_file(argv[1], LIST_SIZE, input_array)) {
        printf("Error reading list from file\n");
        rc = -1;
        goto end;
    }

    array__print(input_array, LIST_SIZE);
    
end:
    return rc;
}
