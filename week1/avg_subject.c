#include <stdio.h>
int main()
{
    int marks[20][5];
    int n = 0;
    double avg[5];
    for (int i = 0; i < 20; i++)
    {
        scanf("%d %d %d %d %d", &marks[i][0], &marks[i][1], &marks[i][2], &marks[i][3], &marks[i][4]);
    }
    for (int i = 0; i < 5; i++)
    {
        
        avg[i] = 0;
        for (int j = 0; j < 20; j++)
        {
            avg[i] += marks[j][i]; // รวมคะแนนของนักเรียนทุกคน
        }
        avg[i] = avg[i] / 20;
    }


    for (int i = 0; i < 5; i++)
    {
        printf("%g\n",avg[i]);
    }

    return 0;
}