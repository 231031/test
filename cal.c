#include <stdio.h>
int calculateArrayStatistic(int number[], int count, int *min, int *max, double *average)
{
    int i = 0;
    double total = 0;

    if (count == 0)
    {
        return -1;
    }

    *min = number[0];
    *max = number[0];

    for (i = 0; i < count; i++)
    {
        if (number[i] < *min)
        {
            *min = number[i];
        }
        if (number[i] > *max)
        {
            *max = number[i];
        }

        total += number[i];
    }

    *average = total / count;
    
    return 1;
}

int main()
{
    int number[5] = {0, 2, 23, 10, 31};
    int count = 5;
    int min = 0;
    int max = 0;
    double average = 0;

    calculateArrayStatistic(number, count, &min, &max, &average);
    printf("%d %d %.2lf", min, max, average);
}