#include <stdio.h>
#include <math.h>
int main()
{
    int marks[20][5];
    int n = 0;
    double avg[20];
    for (int i = 0; i < 20; i++)
    {
        avg[i] = 0;
        for (int j = 0; j < 5; j++)
        {
            scanf("%d", &marks[i][j]);
            avg[i] += marks[i][j]; // รวมคะแนนของนักเรียนแต่ละคน
        }
        avg[i] = avg[i] / 5; // หาค่าเฉลี่ยของนักเรียนแต่ละคน
    }

    for (int i = 0; i < 20; i++)
    {
        if ((int)(avg[i] * 10) % 10 == 0)
        {
            printf("%.0lf\n", avg[i]);
        }
        else if ((int)(avg[i] * 100) % 10 == 0)
        {
            printf("%.1lf\n", avg[i]);
        }
        else
        {
            printf("%.2lf\n", avg[i]);
        }
    }

    return 0;
}