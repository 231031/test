#include <stdio.h>

int main()
{
    int number[5] = {3, 1, 5, 2, 6};
    int n = 5;
    int i = 0;
    int j = 0;
    int minValue = 0;
    int minIndex = 0;

    for (i = 0; i < n; i++)
    {
        j = i + 1;

        while (j < n)
        {
            if (number[j] < number[i])
            {
                minValue = number[j];
                number[j] = number[i];
                number[i] = minValue;
                // j is minIndex
                j++;
            }

            else
            {
                j++;
            }
        }

        printf("%d ", number[i]);
    }
    return 0;
}