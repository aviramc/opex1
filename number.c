#include <stdbool.h>
#include <ctype.h>

bool number__validate_number_string(char * const string)
{
    unsigned int starting_index = 0;
    unsigned int i = 0;

    /* Return false for an empty string */
    if (('\0' == string[0]) || ('\n' == string[0])) {
        return false;
    }

    /* If the first digit is '-' or '+', verify that it is followed by another digit. */
    if (('-' == string[0]) || ('+' == string[0])) {
        if (!isdigit(string[1])) {
            return false;
        }
        /* We've verified the first two characters, */
        starting_index = 2;
    }

    for (i = starting_index; (string[i] != '\0') && (string[i] != '\n'); i++) {
        if (!isdigit(string[i])) {
            return false;
        }
    }

    return true;
}
