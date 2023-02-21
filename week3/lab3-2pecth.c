#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listNode
{
    int data;
    struct listNode *next;
}node;

void createLinklist(node **start) 
{
    char text[100000];
    int num;
    
    node *newnode, *ptr, *preptr;
    *start = NULL;

    fgets(text, 100000, stdin);
    
    char *token = strtok(text, " ");
    while (token != NULL)
        {
            num = atoi(token);
            newnode = (node*)malloc(sizeof(node));
            newnode->data = num;
            newnode->next = NULL;

            if (*start == NULL)
            {
                *start = newnode;
            }
            else
            {
                ptr->next = newnode;
            }
            ptr = newnode;  
            token = strtok(NULL, " ");
        }
    
}

int pop(node **start)
{
    node *ptr = *start, *preptr;
    int data;
    
    while (ptr->next != NULL )
    {
        preptr = ptr;
        ptr = ptr->next;
    }

    data = ptr->data;
    preptr->next = NULL;
    free(ptr);

    return data;
}


void popForward(node *start)
{
    node *ptr = start;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    
    if (start == NULL)
    {
        printf("None");
    }
}

void popBackward(node *start, int count)
{
    
    for (int i = 0; i < count; i++)
    {
        node *ptr = start, *preptr;
        int data;
        while (ptr->next != NULL )
        {
            preptr = ptr;
            ptr = ptr->next;
        }

        data = ptr->data;
        preptr->next = NULL;
        printf("%d ", data);
    }
    
}

int countLinkList(node *start)
{
    int count;
    node *ptr = start;
    while (ptr != NULL)
    {
        ptr = ptr->next;
        count++;
    }
    return count;
}

int main()
{
    int count;
    node *ll;
    createLinklist(&ll);
    count = countLinkList(ll);  
    popForward(ll);
    printf("\n");
    popBackward(ll, count);
    return 0;
}