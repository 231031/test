#include <stdio.h>
#include <stdlib.h>

typedef struct listNode
{
    int data;
    struct listNode *next;
}node;

void push(node **top, int data)
{
    node *newnode;
    newnode = (node*)malloc(sizeof(node));
    newnode->data = data;

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
}

void pop(node **top)
{
    node *ptr = *top;
    if (*top == NULL)
    {
        printf("Stack Overflow");
    }
    else
    {
        *top = (*top)->next;
        printf("data is %d", ptr->data);
        free(ptr);
    }
}

int main()
{
    node *stack;
    push(&stack, 10);
    push(&stack, 20);

    pop(&stack);
    printf("\n");
    pop(&stack);
    return 0;
}