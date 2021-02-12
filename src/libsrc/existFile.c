#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../include/libdasample_in.h"

int existFile(const char *path)
{
    FILE *fp = fopen(path, "r");
    if (fp == NULL)
    {
        return 0;
    }

    fclose(fp);
    return 1;
}
