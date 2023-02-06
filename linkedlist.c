#include <stdio.h>
#include <stdlib.h>

//Structure of list node
typedef struct node
{
    int data;
    struct node *next;
}node;

//Create a linked list
void createList(node **start)
{
    int num;
    node *newNode, *ptr;
    *start = NULL;
    
    printf("Enter data (-1 to end):");
    scanf("%d",&num);
    while(num != -1)
    {
        //Generate new node
        newNode = (node*)malloc(sizeof(node));
        newNode->data = num;    //define data
        newNode->next = NULL;   //no link
        
        //Link new node to the linked list
        if(*start==NULL)
            *start = newNode;  //if first node, link from header
        else
            ptr->next = newNode;    //if latter node, link from current
        ptr = newNode;          //move current to new node
        printf("Enter data (-1 to end):");
        scanf("%d",&num);
    }
}

void display(node *start)
{
    node *ptr = start;             //start
    printf("Data in the list: ");
    while(ptr != NULL)
    {
        printf("%d ",ptr->data);    //print data of current node
        ptr = ptr->next;            //move current to the next node
    }
    printf("\n");
}

void insertBegin(node **start)
{
    node *newNode;
    int num;
    
    printf("Enter data:");
    scanf("%d",&num);
    newNode = (node*)malloc(sizeof(node));
    newNode->data = num;
    newNode->next = *start;
    *start = newNode;
}

void insertEnd(node **start)
{
    node *newNode, *ptr;
    int num;
    
    printf("Enter data:");
    scanf("%d",&num);
    newNode = (node*)malloc(sizeof(node));
    newNode->data = num;
    newNode->next = NULL;
    ptr = *start;
    while(ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = newNode;
}

void deleteBegin(node **start)
{
    node *ptr = *start;//node 1
    *start = (*start)->next; //link to node 2
    free(ptr);
}

void deleteEnd(node **start)
{
    node *ptr = *start, *preptr;
    while(ptr->next != NULL)
    {
        preptr = ptr;   //node n-1
        ptr = ptr->next;//node n
    }
    preptr->next = NULL;
    free(ptr);
}

int main() {
    // Write C code here
    node *ll;
    createList(&ll);
    display(ll);
    insertBegin(&ll);
    display(ll);
    insertEnd(&ll);
    display(ll);
    deleteBegin(&ll);
    display(ll);
    deleteEnd(&ll);
    display(ll);

    return 0;
}