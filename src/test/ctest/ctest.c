#include <stdio.h>
#include <string.h>
#include <libdasample.h>

int main(void)
{

    TEST_SCHEMA schema0[10];
    memset(&schema0[0], 0x00, sizeof(schema0));

    int rtc = refer(0, &schema0);

    printf("rtc=%d\n", rtc);
    if (rtc == 0)
    {
        for (int index = 0; index < 10; index++)
        {
            printf("[%d] int1=%d, int2=%d, char=%s\n", index, schema0[index].testInt, schema0[index].testInt2, schema0[index].testChar);
        }
    }

    ARRAYDATA schema1[10];
    memset(&schema1[0], 0x00, sizeof(schema1));

    rtc = refer(1, &schema1);

    printf("rtc=%d\n", rtc);
    if (rtc == 0)
    {
        for (int index = 0; index < 10; index++)
        {
            printf("[%d] name=%s %s %d %s %d\n", index, schema1[index].name, schema1[index].array[0].name, schema1[index].array[0].data, schema1[index].array[1].name, schema1[index].array[1].data);
        }
    }

    return 0;
}
