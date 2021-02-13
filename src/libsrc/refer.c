#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sqlite3.h>

#include "../../include/libdasample.h"
#include "../include/libdasample_in.h"

// https://qiita.com/Ki4mTaria/items/bce1a6080e537fb1c949

const int (*referFunc[])(void *, int, char **, char **) = {
    referSingleData,
    referArrayData
    };

const char *sql_str[] = {
    "select * from tb_test",
    "select * from arrayData"
};

int refer(int schemaNo, void *buffer)
{
    int rtc = 0;
    sqlite3 *conn = NULL;
    char *err_msg = NULL;

    SQLITE_READ_BUFFER_INFO info;
    memset(&info, 0x00, sizeof(info));
    info.buffer = buffer;

    if (existFile("/tmp/db_test.sqlite3") == 0)
    {
        return -1;
    }

    rtc = sqlite3_open(
        "/tmp/db_test.sqlite3",
        &conn);
    if (rtc != SQLITE_OK)
    {
        return -1;
    }

    rtc = sqlite3_exec(
        conn,
        sql_str[schemaNo],
        referFunc[schemaNo], // callback method
        &info,        // parameter of callback
        &err_msg);

    if (rtc != SQLITE_OK)
    {
        sqlite3_close(conn);
        fprintf(stderr, "%s\n", err_msg);
        sqlite3_free(err_msg);
        return -1;
    }

    rtc = sqlite3_close(conn);
    if (rtc != SQLITE_OK)
    {
        return -1;
    }

    return 0;
}
