/**************************************************************
 * FILENAME:    char_guard.c            REF: DL_LDEF_util
 *
 * DESCRIPTION:
 *      Libarary of functions to preform an attack suite on an
 *      character based parameter.
 *
 * ENVIRONMENT:
 *      macOS High Sierra 10.13.3
 *      Visual Studio Code 1.30
 *           Extensions: danielpinto8zz6.c-cpp-compile-run
 *
 * VERSION:
 *      0.0.0.1
 *
 * AUTHOR(s):
 *      Kevin Colour
 *
 * DATES:
 *      Created: 11Feb2019          Verified Execute: 11Feb2019
 *
****************************************************************/

#ifndef CHAR_GUARD
# define CHAR_GUARD

#include <stdio.h>
#include "../util/util_string.c"

#define t_size_int 17
#define char_attacks {'A', 'O', 'e', 'o', '0', '1', '5', '9', ':', 47, 46, 92, 9, 10, 126, 128, 134}

void    char_attack(void *(*defense)(int test), char *type)
{
    int     attack[t_size_int] = char_attacks;
    int i;

    i = -1;
    if (str_cmp(type, "void\0") == 0)
        while (++i < t_size_int)
        {
            printf("Test: %c\tResult: \"", attack[i]);
            defense(attack[i]);
            printf("\"\n");
        }
    else if (str_cmp(type, "int\0") == 0)
        while (++i < t_size_int)
            printf("Test: \"%c\"\tResult: %11d\n", attack[i], (int)defense(attack[i]));
    else if (str_cmp(type, "char\0") == 0)
        while (++i < t_size_int)
            printf("Test: \"%c\"\tResult: \"%c\"\n", attack[i], (int)defense(attack[i]));
}

#endif
