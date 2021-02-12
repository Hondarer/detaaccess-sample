#ifndef LIBDASAMPLE_H
#define LIBDASAMPLE_H

typedef struct TEST_SCHEMA
{
    int testInt;
    int testInt2;
    char testChar[32];
} TEST_SCHEMA;

int refer(void *buffer);

#endif
