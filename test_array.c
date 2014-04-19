#include <assert.h>
#include <string.h>
#include <stdio.h>

#include "array.h"

void test_find_max_index();
void test_max_to_first();

int main(void)
{
    test_find_max_index();
    test_max_to_first();
    return 0;
}

void test_find_max_index()
{
    int array1[10] = {10, 3, 11, 4, 5, 100, -30, 10, -50, 99};
    int array2[10] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
    int array3[10] = {-10, -10, -10, -10, 0, -10, -10, -10, -10, -10};
    int array4[1] = {1};

    assert(array__find_max_index(array1, 0, 9) == 5);
    assert(array__find_max_index(array2, 0, 9) == 0);
    assert(array__find_max_index(array3, 0, 9) == 4);
    assert(array__find_max_index(array4, 0, 0) == 0);
}

void test_max_to_first()
{
    int array1[10] = {10, 3, 11, 4, 5, 100, -30, 10, -50, 99};
    int array2[10] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
    int array3[10] = {-10, -10, -10, -10, 0, -10, -10, -10, -10, -10};
    int array4[1] = {1};

    array__max_to_first(array1, 0, 9);
    assert((array1[0] == 100) && (array1[5] == 10));

    array__max_to_first(array2, 0, 9);
    assert(array2[0] == 10);

    array__max_to_first(array3, 0, 9);
    assert((array3[0] == 0) && (array3[4] == -10));

    array__max_to_first(array4, 0, 0);
    assert(array4[0] == 1);
}
