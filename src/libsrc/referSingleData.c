
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <parson.h>

#include "../../include/libdasample.h"
#include "../include/libdasample_in.h"

int referSingleData(
    void *info_ptr,
    int col_cnt,
    char **row_txt, // data
    char **col_name)
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
