#include <stdio.h>
#include <string.h>

void changeEnter(char *data)
{
    if (data[strlen(data) - 1] == '\n')
    {
        data[strlen(data) - 1] = '\0';
    }
}

// circular queue
int enqueue(int *rear,int *front, char data[][100], int max, char *token)
{
    int i = 0;
    if (max == 0)
    {
        return -1;
    }

    changeEnter(token);
    if (token[0] == '\0')
    {
        return -1;
    }
    if (*front == 0 && *rear == max -1) // overflow
    {
        printf("FULLqueue\n");
        return -1;
    }
    else if (*front == -1 && *rear == -1)
    {
        *front = 0;
        *rear = 0;
    }
    else if (*rear == max -1 && *front != 0)
    {
        *rear = 0;
    }
    else
    {
        (*rear)++;
    }

    
    while (i < strlen(token))
    {
        data[*rear][i] = token[i];
        i++;
    }
    data[*rear][i] = '\0';
    return 0;
}

int dequeue(int *rear,int *front, char data[][100], int max, int output)
{
    char *val;
    if (*front == -1) // underflow
    {
        printf("None");
        return -1;
    }
    val = data[*front];
    printf("%s ", val);
    if (*front == *rear)
    {
        if (output - 1 != *front)
        { 
            printf("None");
            *front = -1;
            *rear = -1;
            return -1;
        }
        *front = -1;
        *rear = -1;
    }
    else
    {
        if (*front == max - 1)
        {
            *front = 0;
        }
        else
        {
            (*front)++;
        }
    }
    return 0;
}



int main()
{
    int max = 0, i = 0, front = -1, rear = -1;
    int output = 0, check = 0, output2 = 0;
    char dataInput[1000];
    char dataInput2[1000];
    char str[100];
    

    fgets(str, 10 ,stdin);
    sscanf(str, "%d", &max);
    fgets(dataInput, 1000, stdin);
    fgets(str, 10, stdin);
    sscanf(str, "%d", &output);
    char data[max][100];

    fgets(dataInput2, 1000, stdin);
    fgets(str, 10, stdin);
    sscanf(str, "%d", &output2);

    char *token = strtok(dataInput," ");
    while (token != NULL)
    {
        strcpy(str, token);
        //changeEnter(str);
        check = enqueue(&rear, &front, data, max, str);
        if (check == -1)
        {
            break;
        }
        token = strtok(NULL, " ");
    }

    check = 0;
    while (i < output)
    {
        check = dequeue(&rear, &front, data, max, output);
        if (check == -1)
        {
            break;
        }
        i++;
    }
    printf("\n");
    i = 0;
    check = 0;

    token = strtok(dataInput2, " ");
    while (token != NULL)
    {
        strcpy(str, token);
        changeEnter(str);
        check = enqueue(&rear, &front, data, max, str);
        if (check == -1)
        {
            break;
        }
        token = strtok(NULL, " ");
    }

    check = 0;
    i = 0;
    while (i < output2)
    {
        check = dequeue(&rear, &front, data, max, output2);
        if (check == -1)
        {
            break;
        }
        i++;
    }
}