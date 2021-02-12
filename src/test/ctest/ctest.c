#include <stdio.h>
#include <string.h>
#include <libdasample.h>

int main(void)
{
    TEST_SCHEMA schema[10];
    memset(&schema[0], 0x00, sizeof(schema));

    int rtc = refer(&schema);

    printf("rtc=%d\n", rtc);
    if (rtc == 0)
    {
        for (int index = 0; index < 10; index++)
        {
            printf("[%d] int1=%d, int2=%d, char=%s\n", index, schema[index].testInt, schema[index].testInt2, schema[index].testChar);
        }
    }

    return 0;
}
