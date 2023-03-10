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
        return 0;
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
    push(&stack);

    char count;

    scanf("%c", &count);

    if (count == '\n')
    {
        return 0;
    }
    else
    {
        int n = atoi(&count);
        while (n <= 1 || n >= 100000)
        {
            scanf("%c", &count);
        }
        for (int i = 0; i < n; i++)
        {
            pop(&stack);
        }
    }

    return 0;
}