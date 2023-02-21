#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    char data[100];
    struct node *next;
} node;


void enQueue(node **front, node *newNode, node **ptr)
{
    if (*front == NULL)
    {
        *front = newNode;
    }
    else
    {
       (*ptr)->next = newNode;
    }
    (*ptr) = newNode;
}

void createdQueue(node **front, char *str)
{
    int i = 0;
    node *newNode, *ptr;
    char *str2 = str;
    char strInput[100];
    *front = NULL;

    while (*str2 != '\n')
    {
        i = 0;
        while (*str2 != ' ' && *str2 != '\n')
        {
            sscanf(str2, "%c", &strInput[i]);
            i++;
            str2++;
        }
        strInput[i] = '\0';


        //generate newNode
        newNode = (node*) malloc(sizeof(node));
        strcpy(newNode->data, strInput);
        newNode->next = NULL;
        enQueue(front, newNode, &ptr);
        if (*str2 == '\n')
        {
            break;
        }
        str2++; // skip blank space
    }

}

int deQueue(node **front)
{
    node *ptr;
    ptr = *front;
    if (ptr == NULL)
    {
        printf("None\n");
        return -1;
    }
    *front = (*front)->next;

    printf("%s ", ptr->data);
    free(ptr);
    return 0;
}


int main()
{
    char str[10000];
    char countStr[15];
    int count = 0, i = 0,check = 0;
    node *ll;
    fgets(str, 10000, stdin);
    if (str[0] == '\n')
    {
        printf("None\n");
        return 0;
    }
    fgets(countStr, 15, stdin);
    if (countStr[0] == '\n')
    {
        printf("None\n");
        return 0;
    }
    createdQueue(&ll, str);
    sscanf(countStr, "%d", &count);
    if (count == 0)
    {
        printf("None\n");
        return 0;
    }
    while (i < count && check != -1)
    {
        check = deQueue(&ll);
        i++;
    }
    return 0;
}