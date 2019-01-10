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
 *      0.0.0.2
 * 
 * AUTHOR(s):
 *      Kevin Colour
 *
 * DATES:
 *      Created: 23Dec2018          Verified Execute: 09Jan2019
 *
****************************************************************/

#ifndef UTIL_STRING
# define UTIL_STRING

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
    return (*s2 - *s1);
}

char    *str_cpy(char *dest, char *src)
{
    char *head;

    head = dest;
    while (*src)
        *dest++ = *src++;
    *dest = '\0';
    return (head);
}

#endif