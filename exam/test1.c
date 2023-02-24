#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct data
{
    int value;
    int f;
} data;

void sort(int n, int num[])
{
    int i = 0, j = 0, temp = 0;
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
        //printf("%d ", num[i]);
        i++;
    }
}
int getData(data **dataAll)
{
    char input[200];
    char *token;
    int number[100];

    int count = 0;
    int j = 0;
    int i = 0;
    

    fgets(input, 200, stdin);
    token = strtok(input, " "); 
    //token[strlen(token)] = '\0';
    while (token != NULL)
    {
        sscanf(token, "%d", &number[i]);
        i++;
        token = strtok(NULL, " ");
    }
    sort(i, number); // sort number
    *dataAll = (data*)calloc(i, sizeof(data));
    while (j < i)
    {
       (*dataAll)[count].value = number[j]; // define data
        while ((*dataAll)[count].value == number[j] && j < i)
        {
            j++;
            ((*dataAll)[count].f)++;
        }
        count++;
    }
    return count;

}

void displayData(data *dataAll, int count)
{
    int i = 0;
    printf("n: ");
    while (i != count)
    {
        printf("%d ", dataAll[i].value);
        i++;
    }
    printf("\n");
    i = 0;
    printf("f: ");
    while (i < count)
    {
        printf("%d ", dataAll[i].f);
        i++;
    }
}


int findMaxFreq(data *dataAll, int count)
{
    int i = 0; 
    int max = 0;
    int temp = 0;
    temp = dataAll[0].f;
    max = dataAll[0].value;
    while (i < count)
    {
        if (dataAll[i].f > temp)
        {
            max = dataAll[i].value;
            temp = dataAll[i].f;
        }
        else if (dataAll[i].f == temp && dataAll[i].value < max)
        {
            max = dataAll[i].value;
        }
        i++;
    }
    return max;
}

int findMinFreq(data *dataAll, int count)
{
    int i = 0; 
    int min = 0;
    int temp = 0;
    temp = dataAll[0].f;
    min = dataAll[0].value;
    while (i < count)
    {
        if (dataAll[i].f < temp)
        {
            min = dataAll[i].value;
            temp = dataAll[i].f;
        }
        else if (dataAll[i].f == temp && dataAll[i].value < min)
        {
            min = dataAll[i].value;
        }
        i++;
    }
    return min;
}

int main()
{
    data *dataAll;
    int max = 0, min = 0;
    int count = 0;
    count = getData(&dataAll);
    displayData(dataAll, count);

    printf("\n");
    max = findMaxFreq(dataAll, count);
    printf("Max = %d\n",max);
    min = findMinFreq(dataAll, count);
    printf("Min = %d\n",min);

    return 0;
}