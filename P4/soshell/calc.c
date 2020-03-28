#include "shell.h"
void calc(char *value1, char *op, char *value2)
{
    float v1 = atof(value1);
    float v2 = atof(value2);
    float total;
    if (0 == strcmp(op, "+"))
    {
        total = v1 + v2;
    }
    if (0 == strcmp(op, "-"))
    {
        total = v1 - v2;
    }
    if (0 == strcmp(op, "*"))
    {
        total = v1 * v2;
    }
    if (0 == strcmp(op, "/"))
    {
        if (v2 != 0)
        {
            total = v1 / v2;
        }
        else
        {
            printf("Divisão por zero (0)\n");
            return;
        }
    }
    if (0 == strcmp(op, "^"))
    {
        total = powf(v1, v2);
    }
    printf("%f\n", total);
}