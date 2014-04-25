#include <assert.h>

#include "number.h"

static void test_validate_number_string();

int main(void)
{
    test_validate_number_string();
}

static void test_validate_number_string()
{
    assert(number__validate_number_string("123") == true);
    assert(number__validate_number_string("+523") == true);
    assert(number__validate_number_string("-1234567890") == true);
    assert(number__validate_number_string("000") == true);
    assert(number__validate_number_string("+1") == true);
    assert(number__validate_number_string("-9") == true);
    assert(number__validate_number_string("+0") == true);
    assert(number__validate_number_string("-0") == true);

    assert(number__validate_number_string("") == false);
    assert(number__validate_number_string("\0") == false);
    assert(number__validate_number_string("\n") == false);
    assert(number__validate_number_string("-") == false);
    assert(number__validate_number_string("+") == false);
    assert(number__validate_number_string("-X") == false);
    assert(number__validate_number_string("+X") == false);

    assert(number__validate_number_string("A1234") == false);
    assert(number__validate_number_string("ABCDEFG") == false);
    assert(number__validate_number_string("1e3") == false);
    assert(number__validate_number_string(" 3213") == false);
    assert(number__validate_number_string("\t3213 ") == false);
}
