#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <parson.h>

#include "../../include/libdasample.h"
#include "../include/libdasample_in.h"

// https://qiita.com/Ki4mTaria/items/bce1a6080e537fb1c949

typedef struct SQLITE_READ_BUFFER_INFO
{
    int row;
    void *buffer;
} SQLITE_READ_BUFFER_INFO;

int referCore(void *, int, char **, char **);

int refer(void *buffer)
{
    int rtc = 0;
    sqlite3 *conn = NULL;
    char *err_msg = NULL;
    char sql_str[255];
    memset(&sql_str[0], 0x00, sizeof(sql_str));

    SQLITE_READ_BUFFER_INFO info;
    memset(&info, 0x00, sizeof(info));
    info.buffer = buffer;

    if (existFile("/tmp/db_test.sqlite3") == 0)
    {
        return -1;
    }

    rtc = sqlite3_open(
        "/tmp/db_test.sqlite3",
        &conn
    );
    if (rtc != SQLITE_OK)
    {
        return -1;
    }

    snprintf(&sql_str[0], sizeof(sql_str) - 1, "select * from tb_test");
    rtc = sqlite3_exec(
        conn,
        &sql_str[0],
        referCore,   // callback method
        &info,       // parameter of callback
        &err_msg
    );
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

int referCore(
    void *info_ptr,
    int col_cnt,
    char **row_txt, // data
    char **col_name
)
{
    SQLITE_READ_BUFFER_INFO *info = (SQLITE_READ_BUFFER_INFO *)info_ptr;
    TEST_SCHEMA *schema = info->buffer;

    JSON_Value *root_value;
    root_value = json_parse_string(row_txt[1]);
    if (json_value_get_type(root_value) != JSONObject)
    {
        return -1;
    }

    JSON_Object *data;
    data = json_value_get_object(root_value);

    sscanf(row_txt[0], "%d", &(schema + info->row)->testInt);

    char *string;
    string = (char *)json_object_get_string(data, "name");
    if (string != NULL)
    {
        strncpy((schema + info->row)->testChar, string, sizeof(schema->testChar) - 1);
    }

    (schema + info->row)->testInt2 = info->row;

    json_value_free(root_value);

    info->row++;

    return 0;
}
