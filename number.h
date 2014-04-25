/* number.h - common number operations
 */

#ifndef __NUMBER_H__
#define __NUMBER_H__

#include <stdbool.h>
#include <ctype.h>

/* Return true if the given string represents a number, false otherwise.
   A number either begins with '-', '+' or a digit, and is then followed by digits.
   The validation is for decimal numbers and decimal digits.
   The given string must be either NULL-terminated or LF-terminated.
 */
bool number__validate_number_string(char * const string);

#endif /* __NUMBER_H__ */
