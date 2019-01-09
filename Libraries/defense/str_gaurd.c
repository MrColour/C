/**************************************************************
 * FILENAME:    str_gaurd.c            REF: DL_LDEF_util
 * 
 * DESCRIPTION:
 *      Libarary of functions to preform an attack suite on a
 *      string based parameter.
 *
 * ENVIRONMENT:
 *      Windows 10 Home v1803 x64
 *      Visual Studio Code 1.30
 *           Extensions: danielpinto8zz6.c-cpp-compile-run
 *      Installs: mingw-get 0.6.3
 * 
 * VERSION:
 *      0.0.0.1
 * 
 * AUTHOR(s):
 *      Kevin Colour
 *
 * DATES:
 *      Created: 07Jan2019          Verified Execute: 08Jan2018
 *
****************************************************************/

#ifndef STR_GUARD
# define STR_GUARD

#include <stdio.h>
#include "../util/util_string.c"

#define t_size_str 6
#define attacks_str {"abcdef", "Test\0", "Test 2\0", " \0", "\0", " Test \n 3 \t.\0"}

void    str_attack(void *(*defense)(char *test), char *type)
{
    char     *attack[t_size_str] = attacks_str;
    int i;

    i = 0;
    if (ft_strcmp(type, "void\0") == 0)
        while (i < t_size_str)
        {
            printf("Test: \"%s\"\tResult: \"", attack[i]);
            defense(attack[i++]);
            printf("\"\n");
        }
    else if (ft_strcmp(type, "int\0") == 0)
        while (i < t_size_str)
        {
            printf("Test: \"%s\"\tResult: %11d\n", attack[i], (int)defense(attack[i]));
            i++;
        }
    else if (ft_strcmp(type, "string\0") == 0)
        while (i < t_size_str)
        {
            printf("Test: \"%s\"\tResult: \"%s\"\n", attack[i], (char *)defense(attack[i]));
            i++;
        }
}

#endif