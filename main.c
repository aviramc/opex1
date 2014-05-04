#include <string.h>
#include <limits.h>
#include <stdio.h>

#include "subarray.h"
#include "limits.h"
#include "array.h"

#define ARRAY_SIZE (256)        /* The 'n' of the exercise */
/* The size of each sub array of the first (k - 1) arrays. */
#define SUB_ARRAYS_SIZE (ARRAY_SIZE / SUB_ARRAYS)   /* [n/k] */
/* The size of the array k, which will always be larger or equal to SUB_ARRAYS_SIZE */
#define LAST_ARRAY_SIZE (SUB_ARRAYS_SIZE + (ARRAY_SIZE % SUB_ARRAYS))

static unsigned int exercise_sort(int array_to_sort[ARRAY_SIZE]);
static void create_sub_arrays(int input_array[ARRAY_SIZE], int output_arrays[SUB_ARRAYS][LAST_ARRAY_SIZE]);

typedef enum {
    RC_SUCCESS = 0,
    RC_ERROR = -1,
} rc_t;

int main(int argc, char * const argv[])
{
    unsigned int sort_comparisons = 0;
    unsigned int array_find_max_comparisons = 0;
    int input_array[ARRAY_SIZE] = {0};
    rc_t rc = RC_ERROR;

    if (2 != argc) {
        printf("Usage: %s input_file\n", argv[0]);
        rc = RC_ERROR;
        goto end;
    }

    if (!array__read_from_file(argv[1], ARRAY_SIZE, input_array)) {
        printf("Error reading list from file\n");
        rc = RC_ERROR;
        goto end;
    }

    array__reset_comparisons();
    printf("The original array:\n");
    array__print(input_array, ARRAY_SIZE);
    printf("The sorted array:\n");
    sort_comparisons = exercise_sort(input_array);
    printf("\n");
    array_find_max_comparisons = array__get_comparisons();
    printf("Comparisons of all sub-ararys: %d\n", array_find_max_comparisons);
    printf("Comparisons of the maximums of the sub-arrays: %d\n", sort_comparisons);
    printf("Total comparisons: %d\n", array_find_max_comparisons + sort_comparisons);

    rc = RC_SUCCESS;
    
end:
    return rc;
}

/* exercise_sort - sort an array (descending) by dividing it into sub-arrays, then finding the max of each.

   We do this by:
      1. Dividing the array of size n into (k - 1) arrays sized [n / k] and another array with the leftover.
      2. For each such array, we save its starting index and its size (as the size of the last array differs).
      3. We then iterate over all the arrays, for each we find its maximum and put it in the array's starting index.
      4. We find the max of all the arrays and print it. We then increase the starting index of the array to which it
         belongs, thus 'throwing it away', as we no longer need this max value in the beginning of the array.
      5. We do 3-4 over and over, until all the sub-arrays are 'emptied' and all the values have been printed in a
         descending order.

   The function returns the number of comparisons done to find the max of max's in each of the sub-array.
 */
static unsigned int exercise_sort(int array_to_sort[ARRAY_SIZE])
{
    int sub_arrays[SUB_ARRAYS][LAST_ARRAY_SIZE] = {{0}};
    int max_value = 0;
    unsigned int max_array = 0;
    unsigned int sub_arrays_start_index[SUB_ARRAYS] = {0};
    unsigned int sub_arrays_sizes[SUB_ARRAYS] = {0};
    unsigned int current_start_index = 0;
    unsigned int current_array_size = 0;
    unsigned int i = 0;
    unsigned int comparisons = 0;
    unsigned int members_to_print = 0;

    /* Initialize the sizes of the first (k - 1) sub-arrays. */
    for (i = 0; i < SUB_ARRAYS - 1; i++) {
        sub_arrays_sizes[i] = SUB_ARRAYS_SIZE;
    }
    /* Intialize the size of the last array. */
    sub_arrays_sizes[SUB_ARRAYS - 1] = LAST_ARRAY_SIZE;

    create_sub_arrays(array_to_sort, sub_arrays);

    for (i = 0; i < SUB_ARRAYS; i++) {
        current_start_index = sub_arrays_start_index[i];
        current_array_size = sub_arrays_sizes[i];
        array__max_to_first(sub_arrays[i], current_start_index, current_array_size - 1);
    }

    comparisons = 0;
    members_to_print = ARRAY_SIZE;
    while (members_to_print) {
        max_value = INT_MIN;
        for (i = 0; i < SUB_ARRAYS; i++) {
            current_start_index = sub_arrays_start_index[i];
            current_array_size = sub_arrays_sizes[i];

            /* Skip empty sub-arrays */
            if (ARRAY_EMPTY(current_start_index, current_array_size)) {
                continue;
            }

            current_start_index = sub_arrays_start_index[i];
            current_array_size = sub_arrays_sizes[i];
            comparisons += 1;
            if (max_value < sub_arrays[i][current_start_index]) {
                max_value = sub_arrays[i][current_start_index];
                max_array = i;
            }

        }
        printf("%d ", max_value);
        sub_arrays_start_index[max_array] += 1;
        members_to_print -= 1;

        array__max_to_first(sub_arrays[max_array], sub_arrays_start_index[max_array], sub_arrays_sizes[max_array] - 1);
    }

    printf("\n");

    return comparisons;
}

/* create_sub_arrays - divide the input_array (of size n) into (k - 1) sub-arrays of size [n / k]
   and to another sub-array with the rest of the members.

   The sub-arrays are stored in an array of arrays.
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
}
