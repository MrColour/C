/**************************************************************
 * FILENAME:    int_guard.c            REF: DL_LDEF_util
 * 
 * DESCRIPTION:
 *      Libarary of functions to preform an attack suite on an
 *      integer based parameter.
 *
 * ENVIRONMENT:
 *      Windows 10 Home v1803 x64
 *      Visual Studio Code 1.30
 *           Extensions: danielpinto8zz6.c-cpp-compile-run
 *      Installs: mingw-get 0.6.3
 * 
 * VERSION:
 *      0.0.0.5
 * 
 * AUTHOR(s):
 *      Kevin Colour
 *
 * DATES:
 *      Created: 20Dec2018          Verified Execute: 11Jan2019
 *
****************************************************************/

#ifndef INT_GUARD
# define INT_GUARD

#include <stdio.h>
#include "../util/util_string.c"

#define t_size_int 16
#define int_attacks {-2147483648, -2147483647, -10, -7, -1, -0, 0, 1, 2, 5, 7, 9, 10, 42, 2147483647, NULL}

void    int_attack(void *(*defense)(int test), char *type)
{
    int     attack[t_size_int] = int_attacks;
    int i;

    i = -1;
    if (str_cmp(type, "void\0") == 0)
        while (++i < t_size_int)
        {
            printf("Test: %11d\tResult: \"", attack[i]);
            defense(attack[i]);
            printf("\"\n");
        }
    else if (str_cmp(type, "int\0") == 0)
        while (++i < t_size_int)
            printf("Test: %11d\tResult: %11d\n", attack[i], (int)defense(attack[i]));
            
}

void    supressed_int_attack(void *(*defense)(int test), char *type)
{
    int     attack[t_size_int] = int_attacks;
    int i;

    i = -1;
    if (str_cmp(type, "void\0") == 0)
        while (++i < t_size_int)
        {
            printf("Result: \"");
            defense(attack[i]);
            printf("\"\n");
        }
    else if (str_cmp(type, "int\0") == 0)
        while (++i < t_size_int)
            printf("Result: %11d\n", (int)defense(attack[i]));
}

void    int_range_attack(void *(*defense)(int test), char *type, int min, int max)
{
    min = min - 1;
    if (str_cmp(type, "int\0") == 0)
        while (min++ < max)
            printf("Test: %11d\tResult: %11d\n", min, (int)defense(min));
}

#endif
