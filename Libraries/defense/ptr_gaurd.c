/**************************************************************
 * FILENAME:    ptr_gaurd.c            REF: DL_LDEF_util
 * 
 * DESCRIPTION:
 *      Libarary of functions to preform an attack suite
 *      on pointer based parameters.
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

#ifndef PTR_GUARD
# define PTR_GUARD

#include "../util/util_ptr.c"

void    pointer_check(void (defense)(void *test), void *intended, char *type, int size)
{
    void **ptrs;
    ptrs = pointer_inception(size);
    defense(ptrs[size - 1]);
    if (type == "int")
        if ((int)pointer_undo(ptrs[size - 1], size) == (int)intended)
            printf("\t\tPASSED.\nExpected value: %d. You returned: %d\n", (int)(intended), (int)pointer_undo(ptrs[size - 1], size));
        else
            printf("FAILED. Expected value: %d you returned: %d\n", (int)(intended), (int)pointer_undo(ptrs[size - 1], size));
    else
        printf("FAILED. Reason unknown.\n");
}

#endif