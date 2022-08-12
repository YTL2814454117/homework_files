#include "delay.h"
void delay_ms(unsigned int t)
{
    int i;
    for (i = 1; i < t; i++)
    {
        int a = 42000;
        while (a--)
            ;
    }
}