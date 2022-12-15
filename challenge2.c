#include <stdio.h>
int main()
{
    int times = 0;
    double total = 0;
    while (times != -1)
    {
        total = 0;
        printf("How Many Number You Want To Plus? -1 to End: ");
        scanf("%d", &times);
        if (times == -1)
        {
            break;
        }
        double number[times];
        for (int i = 0; i < times; i++)
        {
            printf("Enter number #%d : ",i + 1);
            scanf("%lf", &number[i]);
            total += number[i];
        }
        printf("The Result is : %.2lf\n", total);
    }
    return 0;
}