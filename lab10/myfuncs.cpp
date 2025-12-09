#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "myfuncs.h"

float RH(int r, int h)
{
    return 3.14 * r * r * h;
}

void CE(int mass[], int a, int b)
{
    int c;
    c = mass[a];
    mass[a] = mass[b];
    mass[b] = c;
}

float procent(int n, int precent)
{
    return (float) (n * precent) / 100;
}
