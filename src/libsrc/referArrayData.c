
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <parson.h>

#include "../../include/libdasample.h"
#include "../include/libdasample_in.h"

int referArrayData(
    void *info_ptr,
    int col_cnt,
    char **row_txt, // data
    char **col_name)
{
    SQLITE_READ_BUFFER_INFO *info = (SQLITE_READ_BUFFER_INFO *)info_ptr;
    ARRAYDATA *schema = info->buffer;

    JSON_Value *root_value;
    root_value = json_parse_string(row_txt[1]);
    if (json_value_get_type(root_value) != JSONObject)
    {
        return -1;
    }

    JSON_Object *data;
    data = json_value_get_object(root_value);

    char *string;
    string = (char *)json_object_get_string(data, "name");
    if (string != NULL)
    {
        strncpy((schema + info->row)->name, string, sizeof(schema->name) - 1);
    }

    JSON_Array *array;
    array = json_object_get_array(data, "array");
    if (array != NULL)
    {
        for (int index = 0; index < 2; index++)
        {
            JSON_Object *element;
            element = json_array_get_object(array, index);

            if (element == NULL)
            {
                break;
            }

            char *name2;
            name2 = (char *)json_object_get_string(element, "name2");

            if (name2 != NULL)
            {
                strncpy((schema + info->row)->array[index].name, name2, sizeof(schema->array->name) - 1);
            }

            double data;
            data = json_object_get_number(element, "data2");
            (schema + info->row)->array[index].data = data;
        }
    }

    json_value_free(root_value);

    info->row++;

    return 0;
}
