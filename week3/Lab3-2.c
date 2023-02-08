#include<stdio.h>
#include<math.h>

typedef union INPUT
{
    int num;
    float num2;
    char str[5];
};


int input(int num[])
{
    char str[50];
    char *str2;
    str2 = str;
    int top = 0;

    fgets(str, 50, stdin);
    str2 = str;
    while (*str2 != '\n')
    {
        while (*str2 != ' ' && *str2 != '\n')
        {
            str2++;
        }
        if (*str2 != '\n')
        {
            top++;
        }
    }
    
}

int popForward(int num[], int *top) // print จาก หลัง ไป หน้า
{
    int val;
    if (*top == -1)
    {
        //printf("STACK UNDERFLOW\n");
        return -1;
    }
    else
    {
        val = num[*top];
        (*top)--;
        return val;
        //printf("%d ",val);
    }
}

int popBackward(int num[], int *top, int max) // print จาก หน้า ไป หลัง
{
    int val;
    int i = 0;
    if (*top == max)
    {
        printf("STACK UNDERFLOW\n");
        return -1;
    }
    else
    {
        val = num[*top];
        (*top)++;
        return val;
    }
}

int main()
{
    int top = 0, val = 0, top2 = 0, max = 0;
    int num[50];

    top = input(num);
    if (top == -1)
    {
        return 0;
    }

    max = top + 1;
    while (top2 != max)
    {
        val = popBackward(num, &top2, max);
        if (val != -1)
        {
            printf("%d ", val); 
        }
    }
    printf("\n");


    while(top != -1)
    {
        val = popForward(num ,&top);
        if (val != -1)
        {
            printf("%d ", val);
        }
    }

    return 0;



}