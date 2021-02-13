#ifndef LIBDASAMPLE_IN_H
#define LIBDASAMPLE_IN_H

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct SQLITE_READ_BUFFER_INFO
{
    int row;
    void *buffer;
} SQLITE_READ_BUFFER_INFO;

int existFile(const char *path);

int referSingleData(void *, int, char **, char **);
int referArrayData(void *, int, char **, char **);

#ifdef __cplusplus
}
#endif

#endif
