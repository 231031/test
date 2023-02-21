#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int data;
    struct node *next;
} node;

void push(node **ptr) // insert new element
{

}

void createList(node **top)
{
    *top = NULL;
    node *newNode, *ptr;
    int num;
    char str[50];
    newNode = (node*)malloc(sizeof(node));
    newNode->data = num;
    newNode->next = NULL;
    if (*top == NULL)
    {
        *top = newNode;
    }
    else
    {
        ptr->next = newNode;
    }
    ptr = newNode;
}

void display(node *ptr)
{

}



void pop(node **ptr) // pop last element
{

}

int main()
{
    node *ll;
    createList(&ll);
    return 0;
}