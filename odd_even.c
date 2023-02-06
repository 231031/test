#include <stdio.h>
int main()
{
    int i, j;
    int m, n;

    //
    scanf("%d %d", &j, &i);
    int marks[i][j];
    int odd[i * j];
    int even[i * j];

    m = 0;
    n = 0;

    // input values to array
    for (int p = 0; p < i; p++)
    {
        for (int q = 0; q < j; q++)
        {
            scanf("%d", &marks[p][q]);

            // check odd or even
            if (marks[p][q] % 2 == 0)
            {
                even[m] = marks[p][q];
                m++;
            }
            else
            {
                odd[n] = marks[p][q];
                n++;
            }
        }
    }
    if (n == 0)
    {
        printf("None\n");
    }
    else
    {
        for (int p = 0; p < n; p++)
        {
            printf("%d ", odd[p]);
        }
        printf("\n");
    }
    if (m == 0)
    {
        printf("None\n");
    }
    else
    {
        for (int q = 0; q < m; q++)
        {
            printf("%d ", even[q]);
        }
    }

    return 0;
}