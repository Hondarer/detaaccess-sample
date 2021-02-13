#ifndef LIBDASAMPLE_H
#define LIBDASAMPLE_H

typedef struct TEST_SCHEMA
{
    int testInt;
    int testInt2;
    char testChar[32];
} TEST_SCHEMA;

typedef struct ARRAYDATA
{
    char name[32];
    struct
    {
        char name[32];
        int data;
    } array[2];
} ARRAYDATA;

int refer(int schemaNo, void *buffer);

#endif
