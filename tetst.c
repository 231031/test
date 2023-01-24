#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct {
    double x, y;
} point;

void tran(point *p, double dx)
{
    printf("%lf", (*p).x);
    printf("%lf", p->x);
}
int main()
{/*
    point *student = calloc(1, sizeof(double));
FILE *f = fopen("num.txt", "r");
fscanf(f, "%lf", &student[0].x);
printf("%lf", student[0].x);*/
    double d[] = {2.5 , 2.5 , 2.5};
    printf("%lu",sizeof(d));
}