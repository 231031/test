/*
Problem :

Implement stacks using linked list

Input : 

First Line : An array, arr (1 <= arr.length <= 10^5)

Second Line : How many pop, (1<= pop <= 10^5)

Output : 

First Line to pop Line : Each stack member from Pop. If stack Empty return None

1 2 3 4 5 6
4
​output 6 5 4 3

0 0 0 1 0
6
output 0 1 0 0 0 None
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listNode
{
    char *data;
    struct listNode *next;
}node;

int push(node **top)
{
    char text[10000];

    fgets(text, 100000, stdin);
   
    char *token;
    char *check;
    check = strtok(text, "\n");
    token = strtok(text, " ");

    if (check == NULL)
    {
        return -1;
    }
    

    while (token != NULL)
    {
        node *newnode;
        newnode = (node*)malloc(sizeof(node));
        newnode->data = token;

        if (*top == NULL)
        {
            newnode->next = NULL;
            *top = newnode;
        }
        else
        {
            newnode->next = *top;
            *top = newnode;
        }
        token = strtok(NULL, " ");
    }
    
}

void pop(node **top)
{
    
    node *ptr = *top;
    if (*top == NULL)
    {
        printf("None ");
    }
    else
    {
        *top = (*top)->next;
        printf("%s ", ptr->data);
        free(ptr);
    }
}

int main()
{
    node *stack = NULL;
    int check = 0;
    check = push(&stack);
    if (check == -1)
    {
        printf("None\n");
        return 0;
    }
    
    int count;

    scanf("%d", &count);
    
    for (int i = 0; i < count; i++)
    {
        pop(&stack);
    }

    return 0;
}