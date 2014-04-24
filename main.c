/* TODO: Makefile */
/* TODO: Use std types? */
/* TODO: Go over unnecessary includes */
#include <string.h>
#include <stdio.h>

#include "limits.h"
#include "array.h"

#define ARRAY_SIZE (8)        /* The 'n' of the exercise */
#define SUB_ARRAYS (4)        /* The 'k' of the exercise */
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

    printf("The original array:\n");
    array__print(input_array, ARRAY_SIZE);
    printf("The sorted array:\n");
    exercise_sort(input_array);
    
end:
    return rc;
}

/* TODO: Put these in their own file? */
/* exercise_sort - sort an array (descending) by dividing it into sub-arrays, then finding the max of each.

   We do this by:
      1. Dividing the array of size n into (k - 1) arrays sized [n / k] and another array with the leftover.
      2. For each such array, we save its starting index and its size (as the size of the last array differs).
      3. We then iterate over all the arrays, for each we find its maximum and put it in the array's starting index.
      4. We find the max of all the arrays and print it. We then increase the starting index of the array to which it
         belongs, thus 'throwing it away', as we no longer need this max value in the beginning of the array.
      5. We do 3-4 over and over, until all the sub-arrays are 'emptied' and all the values have been printed in a
         descending order.
 */
static void exercise_sort(int array_to_sort[ARRAY_SIZE])
{
    int sub_arrays[SUB_ARRAYS][LAST_ARRAY_SIZE] = {0};
    int max_value = 0;
    unsigned int max_array = 0;
    unsigned int first_array_index = 0;
    unsigned int sub_arrays_start_index[SUB_ARRAYS] = {0};
    unsigned int sub_arrays_sizes[SUB_ARRAYS] = {0};
    unsigned int current_start_index = 0;
    unsigned int current_array_size = 0;
    unsigned int i = 0;

    /* Initialize the sizes of the first (k - 1) sub-arrays. */
    for (i = 0; i < SUB_ARRAYS - 1; i++) {
        sub_arrays_sizes[i] = SUB_ARRAYS_SIZE;
    }
    /* Intialize the size of the last array. */
    sub_arrays_sizes[SUB_ARRAYS - 1] = LAST_ARRAY_SIZE;
    
    create_sub_arrays(array_to_sort, sub_arrays);

    for (first_array_index = 0; first_array_index < SUB_ARRAYS; ) {
        /* Initially set the max index to the index of the max of the first array. */
        current_start_index = sub_arrays_start_index[first_array_index];
        current_array_size = sub_arrays_sizes[first_array_index];
        array__max_to_first(sub_arrays[first_array_index], current_start_index, current_array_size);
        max_value = sub_arrays[first_array_index][current_start_index];
        max_array = first_array_index;

        /* Go over all the other sub arrays and:
             - For each, find its max value.
             - Compare its max value to the other sub-arrays' max values.
             - Find the max value of all the sub-arrays and the index of the sub-array that contains the value.
         */
        for (i = first_array_index + 1; i < SUB_ARRAYS; i++) {
            current_start_index = sub_arrays_start_index[i];
            current_array_size = sub_arrays_sizes[i];
            /* Skip empty sub-arrays */
            if (ARRAY_EMPTY(current_start_index, current_array_size)) {
                continue;
            }

            array__max_to_first(sub_arrays[i], current_start_index, current_array_size);
            if (max_value < sub_arrays[i][current_start_index]) {
                max_value = sub_arrays[i][current_start_index];
                max_array = i;
            }
        }

        /* TODO: Should we store the max value or just print it? */
        printf("%d ", max_value);
        sub_arrays_start_index[max_array] += 1;

        /* The the first array has been emptied, skip it until we have a non empty sub-array */
        while (ARRAY_EMPTY(sub_arrays_start_index[first_array_index], sub_arrays_sizes[first_array_index])) {
            first_array_index += 1;
        }
    }
    printf("\n");
}

/* TODO: Add tests to this function */
/* create_sub_arrays - divide the input_array (of size n) into (k - 1) sub-arrays of size [n / k]
   and to another sub-array with the rest of the members.

   The sub-arrays are stored in an array of an array.
 */
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

    /*~~~*/
    for (i = 0; i < SUB_ARRAYS; i++) {
        for (j = 0; j < LAST_ARRAY_SIZE; j++) {
            printf("%d ", output_arrays[i][j]);
        }
        printf("\n");
    }
}
