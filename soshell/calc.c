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
    else if (0 == strcmp(op, "-"))
    {
        total = v1 - v2;
    }
    else if (0 == strcmp(op, "*"))
    {
        total = v1 * v2;
    }
    else if (0 == strcmp(op, "/"))
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
    else if (0 == strcmp(op, "^"))
    {
        total = powf(v1, v2);
    }
    else
    {
        printf("Operador matemático inválido\n");
        return;
    }
    printf("%f %s %f = %f\n", v1, op, v2, total);
}
void bits(char *op1, char *op, char *op2)
{
    int bit1 = atoi(op1);
    int bit2 = atoi(op2);
    int value;
    if (0 == strcmp(op, "&")) // AND
    {
        value = bit1 & bit2;
    }
    else if (0 == strcmp(op, "^")) // exclusive OR
    {
        value = bit1 ^ bit2;
    }
    else if (0 == strcmp(op, "|")) // inclusive OR
    {
        value = bit1 | bit2;
    }
    else if (0 == strcmp(op, "~")) // AND
    {
        value = ~bit1;
        printf("~%d = %d\n", bit1, value);
        return;
    }
    else if (0 == strcmp(op, "<<"))
    {
        value = bit1 << bit2;
    }
    else if (0 == strcmp(op, ">>"))
    {
        value = bit1 >> bit2;
    }
    else
    {
        printf("Operador binário inválido\n");
        return;
    }
    printf("%d %s %d = %d\n", bit1, op, bit2, value);
}