/**************************************************************
 * FILENAME:    util_string.c            REF: DL_USTR_util
 * 
 * DESCRIPTION:
 *      Libarary of utility functions dealing with strings
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
 *      Created: 23Dec2018          Verified Execute: 25Jan2019
 *
****************************************************************/

#ifndef UTIL_STRING
# define UTIL_STRING

#include <unistd.h>

int     str_len(char *str)
{
    char *head;

    head = str;
    while (*str && str++);
    return (str - head);
}

int     str_cmp(char *s1, char *s2)
{
    while (*s1 && *s2 && *s1 == *s2)
    {
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}

char    *str_cpy_n(char *dest, char *src, int n)
{
    char *head;

    head = dest;
    if (n < 0)
    {
        write(1, "Error in value of n.\n METHOD \t\'str_cpy_n\'\n", 42);
    }
    while (n-- > 0)
        if (*src)
            *dest++ = *src++;
        else
            *dest++ = '\0';
    return (head);
}

char    *str_cpy(char *dest, char *src)
{
    return (str_cpy_n(dest, src, str_len(src)));
}

#endif