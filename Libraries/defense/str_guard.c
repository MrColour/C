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
 *      0.0.0.3
 * 
 * AUTHOR(s):
 *      Kevin Colour
 *
 * DATES:
 *      Created: 07Jan2019          Verified Execute: 09Jan2019
 *
****************************************************************/

#ifndef STR_GUARD
# define STR_GUARD

#include <stdio.h>
#include <stdlib.h>
#include "../util/util_string.c"

#define t_size_str 11
#define str_attacks {"abcdef", "Test\0", "Test 2\0", " \0", "\0", " 42 \n 3 \t.\0", "-123\0", "+123\0", "+-10\0", "-0\0", "087 iou\0"}

void    str_attack_m(void *(*defense)(char *test), char *type)
{
    int i;
    char    *attack[t_size_str];
    char    *source[t_size_str] = str_attacks;

    i = -1;
    while (++i < t_size_str)
    {
        attack[i] = malloc(sizeof(char) * (str_len(source[i]) + 1));
        attack[i] = str_cpy(attack[i], source[i]);
    }

    i = -1;
    if (str_cmp(type, "void\0") == 0)
        while (++i < t_size_str)
        {
            printf("Test: \"%s\"\tResult: \"", source[i]);
            defense(attack[i]);
            printf("\"\n");
        }
    else if (str_cmp(type, "int\0") == 0)
        while (++i < t_size_str)
            printf("Test: \"%s\"\tResult: %11d\n", source[i], (int)defense(attack[i]));
    else if (str_cmp(type, "string\0") == 0)
        while (++i < t_size_str)
            printf("Test: \"%s\"\tResult: \"%s\"\n", source[i], (char *)defense(attack[i]));

    i = -1;
    while (++i < t_size_str)
        free(attack[i]);
}

void    str_attack(void *(*defense)(char *test), char *type)
{
    char     *attack[t_size_str] = str_attacks;
    int i;

    i = -1;
    if (str_cmp(type, "void\0") == 0)
        while (++i < t_size_str)
        {
            printf("Test: \"%s\"\tResult: \"", attack[i]);
            defense(attack[i]);
            printf("\"\n");
        }
    else if (str_cmp(type, "int\0") == 0)
        while (++i < t_size_str)
            printf("Test: \"%s\"\tResult: %11d\n", attack[i], (int)defense(attack[i]));
    else if (str_cmp(type, "string\0") == 0)
        while (++i < t_size_str)
            printf("Test: \"%s\"\tResult: \"%s\"\n", attack[i], (char *)defense(attack[i]));
}

void    str_attack_expected(void *(*defense)(char *test), void *(*expected)(char *test), char *type)
{
    int i;
    char    *attack[t_size_str];
    char    *verify[t_size_str];
    char    *source[t_size_str] = str_attacks;

    i = -1;
    while (++i < t_size_str)
    {
        attack[i] = malloc(sizeof(char) * (str_len(source[i]) + 1));
        verify[i] = malloc(sizeof(char) * (str_len(source[i]) + 1));
        attack[i] = str_cpy(attack[i], source[i]);
        verify[i] = str_cpy(verify[i], source[i]);
    }

    i = -1;
    if (str_cmp(type, "void\0") == 0)
        while (++i < t_size_str)
        {
            printf("Test: \"%s\"\tResult: \"", source[i]);
            defense(attack[i]);
            printf("\" Expected: \"");
            expected(verify[i]);
            printf("Testing");
        }
    else if (str_cmp(type, "int\0") == 0)
        while (++i < t_size_str)
            printf("Test: \"%s\"\tResult: %11d\tExpected: %11d\n", source[i], (int)defense(attack[i]), (int)expected(verify[i]));
    else if (str_cmp(type, "string\0") == 0)
        while (++i < t_size_str)
            printf("Test: \"%s\"\tResult: \"%s\"\tExpected: \"%s\"\n", source[i], (char *)defense(attack[i]), (char *)expected(verify[i]));

    i = -1;
    while (++i < t_size_str)
        free(attack[i]);
}

#endif