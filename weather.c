#include <stdio.h>
int main()
{
    int weather[4][7] = {{1, 2, 3, 3, 3, 1, 1},
                         {2, 2, 3, 3, 3, 3, 1},
                         {2, 2, 1, 1, 2, 1, 1},
                         {3, 2, 1, 3, 2, 1, 2}};
    int week = 0;
    int day = 0;

    while (week != -1)
    {
        printf("Which week(1 - 4)? ");
        scanf("%d", &week);
        if (week == -1)
        {
            break;
        }
        printf("Which day(1 - 7)? ");
        scanf("%d", &day);

        if (weather[week - 1][day - 1] == 1)
        {
            printf("Week %d, Day %d was sunny\n", week, day);
        }
        else if (weather[week - 1][day - 1] == 2)
        {
            printf("Week %d, Day %d was cloudy\n", week, day);
        }
        else if (weather[week - 1][day - 1] == 3)
        {
            printf("Week %d, Day %d was rainy\n", week, day);
        }
    }
}