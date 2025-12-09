#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "myfuncs.h"

int main()
{
    // lab 5.1 RH
    int a, b;
    printf("Enter radius ->\n");
    scanf("%d", & a);
    printf("Enter height ->\n");
    scanf("%d", & b);
    float V = RH(a, b);
    printf("Volume V is: %.2f\n", V);

    // 5.2 CE
    int *p;
    int i, n;
    printf("Enter an array size: ");
    scanf("%d", &n);
    srand(time(NULL));
    p = (int *)malloc(n * sizeof(int));
    for(i=0; i<n; i++)
    {
        p[i] = rand() % 5;
    }
    printf("Source array: ");
    for(i=0; i<n ; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");
    int e1, e2;
    printf("Enter element idxs: ");
    scanf("%d", &e1);
    scanf("%d", &e2);
    CE(p, e1, e2);
    printf("Modified array: ");
    for(i=0; i<n; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");
    free(p);

    // lab 5.3
    int c, d;
    float r;
    printf("Enter any integer:\n");
    scanf("%d", &c);
    printf("Enter percent:\n");
    scanf("%d", &d);
    r = procent(c, d);
    printf("Your percent is: %.2f", r);

    return 0;
}
