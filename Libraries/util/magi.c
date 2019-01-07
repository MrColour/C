/**************************************************************
 * FILENAME:    magi.c            REF: DL_MAGI_util
 * 
 * DESCRIPTION:
 *       Libarary of magical functions.
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
 * NOTES:
 *      Witchcraft.
 * 
 * AUTHOR(s):
 *      Kevin Colour
 *
 * DATES:
 *      Created: 20Dec2018          Verified Execute: 21Dec2018
 *
****************************************************************/

#ifndef MAGI
# define MAGI

#include <unistd.h>
#include <stdarg.h>

int     ft_atoi_mod(char *str)
{
    int result;

    result = 0;
    while ('0' <= *str && *str <= '9')
        result = (result * 10) + (*str++ - '0');
    return (result);
}

#define nl(...) nln(#__VA_ARGS__)
void    nln(char *str)
{
    int times;

    if (*str == 0)
        write(1, "\n", 1);
    else
    {
        times = ft_atoi_mod(str);
        write(1, "\n", 1);
        if (times == 0)
            write(1, "Sir we have a problem in the given input.\n", 42);
        else
            while (times-- > 0)
                write(1, "\n", 1);
    }
}

#endif