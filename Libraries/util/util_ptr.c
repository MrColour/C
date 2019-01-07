/**************************************************************
 * FILENAME:    util_ptr.c            REF: DL_UPTR_util
 * 
 * DESCRIPTION:
 *      Libarary of utility functions dealing with pointers
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
 *      Created: 23Dec2018          Verified Execute: 23Dec2018
 *
****************************************************************/

#ifndef UTIL_PTR
# define UTIL_PTR

#include <stdio.h>

#ifndef TEST_INIT
# define TEST_INIT ('T' + 'E' + 'S' + 'T')
#endif

void    **dbg_pointer_inception(int size)
{
    int a;
    int i;
    volatile void **ptr_array;

    i = 0;
    a = TEST_INIT;
    if (size < 1)
        return (0);
    ptr_array = (void **)(malloc(sizeof(ptr_array) * size));
    if (!(ptr_array))
        return (0);
    *ptr_array = &a;
    while (i < size - 1)
    {
        ptr_array[i + 1] = &ptr_array[i++];
        printf("This adress: %d points to adress: %d\n", &ptr_array[i - 1], ptr_array[i - 1]);
    }
    if (i != size - 1)
        printf("We encountered undefined behavior");
    return (ptr_array);
}

void    *dbg_pointer_undo(void *addresses, int undo_amount)
{
    void *address;
    address = addresses;
    while (undo_amount-- > 0)
    {
        printf("This adress: %d points to adress: %d\n", address, *(int*)address);
        address = *(int *)address;
    }
    return (address);
}

void    **pointer_inception(int size)
{
    int a;
    int i;
    void **ptr_array;

    i = 0;
    a = TEST_INIT;
    if (size < 1)
        return (0);
    ptr_array = (void **)(malloc(sizeof(ptr_array) * size));
    if (!(ptr_array))
        return (0);
    *ptr_array = &a;
    while (i < size - 1)
        ptr_array[i + 1] = &ptr_array[i++];
    return (ptr_array);
}

void    *pointer_undo(void *addresses, int undo_amount)
{
    void *address;
    address = addresses;
    while (undo_amount-- > 0)
        address = *(int *)address;
    return (address);
}

#endif