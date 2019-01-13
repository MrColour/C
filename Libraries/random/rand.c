/**************************************************************
 * FILENAME:    rand.c            REF: DL_RAND_random
 * 
 * DESCRIPTION:
 *      Libarary of functions to produce pseudo-random
 *      data structures.
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
 *      Created: 20Dec2018          Verified Execute: 12Jan2018
 *
****************************************************************/

#ifndef RAND
# define RAND

#include <stdlib.h>
#include <time.h>

int rand_min_max(int min, int max)
{
    int a;
    if (min >= max)
        return (int)NULL;
    a = (rand() % (max + 1 - min)) + min;
    return a;
}

#endif