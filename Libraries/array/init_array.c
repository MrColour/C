#include <stdlib.h>

#ifndef INIT_ARRAY
# define INIT_ARRAY

int *create_1x_int_matrix(int x, int **dst)
{
    if (x >= 0)
    {
        dst = (int *)(malloc(sizeof(*dst) * x));
        while (x > 0)
            *dst++ = NULL;
        return *dst;
    }
    return (0);
}

#endif