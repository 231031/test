#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define CHAR_MAX 100000

typedef struct node
{
    char data[32];
    struct node *next;
} node;

void push(node **top, charch);
int pop(node top);
char *peek(node top);
void display(node top);

void push(node top, char ch)
{

    node *newNode, ptr;
    newNode = (node)malloc(sizeof(node));
    strcpy(newNode->data, ch);
    newNode->next = NULL;
    if (*top == NULL)
        top = newNode;
    else
    {
        newNode->next = (struct node)*top;
        top = newNode;
    }
}

int pop(node **top)
{
    nodefreeNode = *top;
    top = (node)freeNode->next;
    free(freeNode);
    if (top == NULL)
    {
        return -1;
    }
    return 1;
}

char peek(node top)
{
    return (*top)->data;
}

void display(node top)
{
    node ptr =top;
    if (top == NULL)
        return;
    while (1)
    {
        if (ptr == NULL) break;
        printf("%s ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main()
{
    nodestack_forward = NULL;
    node stack_backward = NULL;

    char buffer[CHAR_MAX];
    chartoken;
    fgets(buffer, CHAR_MAX, stdin);
    if(buffer[strlen(buffer) - 1] == '\n'){
        buffer[strlen(buffer) - 1] = '\0';
    }
    token = strtok(buffer, " ");
    while (token != NULL)
    {
        push(&stack_forward,token);
        token = strtok(NULL, " ");
    }
    while(1){
        push(&stack_backward,peek(&stack_forward));
        if(pop(&stack_forward) == -1) break;
    }
    display(&stack_backward);
    while(1){
        push(&stack_forward,peek(&stack_backward));
        if(pop(&stack_backward) == -1) break;
    }
    display(&stack_forward);
    return 0;
}