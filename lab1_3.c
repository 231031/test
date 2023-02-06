#include<stdio.h>
int interchange(int *x, int *y)
{
    
}
int main()
{
    int n = 0;
    scanf("%d", &n);
    int i = 0;
    int j = 0;
    int temp = 0;
    int *temp2;
    int *temp3;
    int num[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }

    i = 0;
    while (i != n)
    {
        j = i + 1;
        while (j != n)
        {
            if (num[j] < num[i])
            {
                temp = num[i];
                num[i] =num[j];
                num[j] = temp;
                j++;
            }
            else
            {
                j++;
            }
        }
        printf("%d ", num[i]);
        i++;
    }
    printf("\n");

    // create new array and replace existing array index 1 and n - 2 by new array
    temp2 = &num[1];
    //printf("%d\n", *temp2);
    for (i = 0; i < n; i++)
    {
        printf("%d ", num[i]);
    }
}