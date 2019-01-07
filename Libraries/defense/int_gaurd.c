/**************************************************************
 * FILENAME:    int_gaurd.c            REF: DL_LDEF_util
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
 *      0.0.0.2
 * 
 * AUTHOR(s):
 *      Kevin Colour
 *
 * DATES:
 *      Created: 20Dec2018          Verified Execute: 21Dec2018
 *
****************************************************************/

#ifndef INT_GUARD
# define INT_GUARD

#include <stdio.h>

#define t_size 14
#define attacks {2147483648, -2147483647, -10, -1, 0, 1, 2, 5, 7, 9, 10, 42, 2147483647, NULL}

void    int_attack(void *(*defense)(int test), char *type)
{
    int     attack[t_size] = attacks;
    int i;

    i = 0;
    if (type == "void")
        while (i < t_size)
        {
            printf("Test: %11d\tResult: ", attack[i]);
            defense(attack[i++]);
            write(1, "\n", 1);
        }
    else if (type == "int")
        while (i < t_size)
            printf("Test: %11d\tResult: %11d\n ", attack[i], (int)defense(attack[i++]));
}

#endif