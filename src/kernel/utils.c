#include "utils.h"

void mem_copy(char *src, char *dest, int nbytes)
{
    for (int i = 0; i < nbytes; i++)
    {
        dest[i] = src[i];
    }
}