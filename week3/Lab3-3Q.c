#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node
{
    char *data;
    struct Node *next;
} node;

typedef struct Stack
{
    struct Node *top;
} stack;

void push(stack *st, char *str)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = strdup(str);
    newNode->next = st->top;
    st->top = newNode;
}

char *pop(stack *st)
{
    if (st->top == NULL)
    {
        return "None";
    }
    node *temp = st->top;
    st->top = temp->next;
    char *str = strdup(temp->data);
    free(temp);
    return str;
}

int main()
{
    stack *st = (stack *)malloc(sizeof(stack));
    st->top = NULL;
    int cnt;
    char str[1000];

    fgets(str, 1000, stdin);
    if (str[strlen(str) - 1] == '\n')
    {
        str[strlen(str) - 1] = '\0';
    }

    char *ptr = strtok(str, " ");
    while (ptr != NULL)
    {
        push(st, ptr);
        ptr = strtok(NULL, " ");
        cnt++;
    }

    scanf("%d", &cnt);
    for (int i = 0; i < cnt; i++)
    {
        char *c = pop(st);
        printf("%s ", c);
    }
    return 0;
}
