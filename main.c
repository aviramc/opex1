/* TODO: Use std types? */
/* TODO: Go over unnecessary includes */
#include <string.h>
#include <stdio.h>

#include "limits.h"
#include "array.h"

#define ARRAY_SIZE (8)        /* The 'n' of the exercise */
#define SUB_ARRAYS (3)        /* The 'k' of the exercise */
/* The size of each sub array of the first (k - 1) arrays. */
#define SUB_ARRAYS_SIZE (ARRAY_SIZE / SUB_ARRAYS)   /* [n/k] */
/* The size of the array k, which will always be larger or equal to SUB_ARRAYS_SIZE */
#define LAST_ARRAY_SIZE (SUB_ARRAYS_SIZE + (ARRAY_SIZE % SUB_ARRAYS))

static void exercise_sort(int array_to_sort[ARRAY_SIZE]);
static void create_sub_arrays(int input_array[ARRAY_SIZE], int output_arrays[SUB_ARRAYS][LAST_ARRAY_SIZE]);

int main(int argc, char * const argv[])
{
    int input_array[ARRAY_SIZE] = {0};
    int rc = -1;

    if (2 != argc) {
        printf("Usage: %s input_file\n", argv[0]);
        rc = -1;
        goto end;
    }

    if (!array__read_from_file(argv[1], ARRAY_SIZE, input_array)) {
        printf("Error reading list from file\n");
        rc = -1;
        goto end;
    }

    array__print(input_array, ARRAY_SIZE); /*~~~*/
    exercise_sort(input_array);
    
end:
    return rc;
}

/* TODO: Put these in their own file? */
/* TODO: Divide into:
          - Array of the smaller sub arrays.
          - A single last array.
         Since the single array is bigger, it's fine to treat it as a special case.
 */
static void exercise_sort(int array_to_sort[ARRAY_SIZE])
{
    int sub_arrays[SUB_ARRAYS][LAST_ARRAY_SIZE] = {0};
    int max_value = 0;
    unsigned int current_max_index = 0;
    unsigned int last_array_index = 0;

    unsigned int sub_arrays_start_index[SUB_ARRAYS] = {0};
    unsigned int sub_arrays_sizes[SUB_ARRAYS] = {0};
    unsigned int current_start_index = 0;
    unsigned int current_array_size = 0;
    unsigned int array_with_max = 0;
    unsigned int i = 0;

    for (i = 0; i < SUB_ARRAYS - 1; i++) {
        sub_arrays_sizes[i] = SUB_ARRAYS_SIZE;
    }
    sub_arrays_sizes[SUB_ARRAYS - 1] = LAST_ARRAY_SIZE;
    
    /*~~~*/
    create_sub_arrays(array_to_sort, sub_arrays);

    unsigned int j;
    for (i = 0; i < SUB_ARRAYS; i++) {
        for (j = 0; j < LAST_ARRAY_SIZE; j++) {
            printf("%d ", sub_arrays[i][j]);
        }
        printf("\n");
    }
    /*~~~*/

    /* TODO: We should end the main loop when the last array ends. */
    while (1) {
        array__max_to_first(sub_arrays[SUB_ARRAYS - 1]);
        max_value = 
        for (i = 0; i < SUB_ARRAYS - 1; i++) {
            current_start_index = sub_arrays_start_index[i];
            current_array_size = sub_arrays_sizes[i];
            if (ARRAY_EMPTY(current_start_index, current_array_size)) {
                continue;
            }
        
        }
    }
}

static void create_sub_arrays(int input_array[ARRAY_SIZE], int output_arrays[SUB_ARRAYS][LAST_ARRAY_SIZE])
{
    unsigned int i = 0, j = 0;

    /* Set the (k - 1) shorter arrays. */
    for (i = 0; i < SUB_ARRAYS - 1; i++) {
        for (j = 0; j < SUB_ARRAYS_SIZE; j++) {
            output_arrays[i][j] = input_array[(i * SUB_ARRAYS_SIZE) + j];
        }
    }

    /* Set the last and longer array. */
    for (i = 0; i < LAST_ARRAY_SIZE; i++) {
        output_arrays[SUB_ARRAYS - 1][i] = input_array[ARRAY_SIZE - LAST_ARRAY_SIZE + i];
    }
}
