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
 *      0.0.0.1
 * 
 * AUTHOR(s):
 *      Kevin Colour
 *
 * DATES:
 *      Created: 23Dec2018          Verified Execute: 08Jan2018
 *
****************************************************************/

#ifndef UTIL_STRING
# define UTIL_STRING

int     ft_strcmp(char *s1, char *s2)
{
    while (*s1 && *s2 && *s1 == *s2)
    {
        s1++;
        s2++;
    }
    return (*s2 - *s1);
}

#endif