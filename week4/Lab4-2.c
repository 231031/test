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
    char *token;
    *front = NULL;

    token = strtok(str, " ");
    while (token != NULL)
    {
        if (token[strlen(token) - 1] == '\n') // check \n 
        {
            token[strlen(token) - 1] = '\0';
        }
        else
        {
            token[strlen(token)] = '\0';
        }

        //generate newNode
        newNode = (node*) malloc(sizeof(node)); 
        strcpy(newNode->data, token);
        newNode->next = NULL;
        enQueue(front, newNode, &ptr); // add newNode to queue

        token = strtok(NULL, " ");
    }

}

int deQueue(node **front)
{
    node *ptr;
    ptr = *front;
    if (ptr == NULL)
    {
        printf("None ");
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

    // input
    fgets(str, 10000, stdin);
    if (str[0] == '\n') // check enter
    {
        printf("None\n");
        return 0;
    }
    fgets(countStr, 15, stdin);
    if (countStr[0] == '\n') // check enter
    {
        printf("None\n");
        return 0;
    }

    // enqueue in createdQueue function
    createdQueue(&ll, str);


    //dequeue
    sscanf(countStr, "%d", &count); 
    if (count == 0)
    {
        printf("None\n");
        return 0;
    }
    while (i < count)
    {
        check = deQueue(&ll);
        i++;
    }
    return 0;
}