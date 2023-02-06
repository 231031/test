#include <stdio.h>
#include <stdlib.h>

// Structure of list node
typedef struct node
{
    int data;
    struct node *next;
} node;

void createList(node **start)
{
    int i = 0, j = 0;
    int num[20];
    char str[50];
    char *str2;
    char temp;
    node *newNode, *ptr;
    *start = NULL;

    // user input
    fgets(str, 50, stdin);

    // count blank spaces
    while (str[j] != 'E')
    {
        if (str[j] == ' ') // check blank space
        {
            i++;
        }
        j++;
    }
    // printf("blank space: %d\n", i);

    str2 = str;
    j = 0;
    // convert string to array int
    while (j < i)
    {
        sscanf(str2, "%d %c", &num[j], &temp);
        if (num[j] >= 10) // เลข 2 หลัก + blank space
        {
            str2++;
            str2++;
            str2++;
        }
        else if (num[j] >= 1) // เลข 1 หลัก + blank space
        {
            str2++;
            str2++;
        }
        /*
        else if (num[j] >= -9) // เครื่องหมายลบ + เลข 1 หลัก + blank space
        {
            str2++;
            str2++;
            str2++;
        }
        else if (num[j] >= -99) // เครื่องหมายลบ + เลข 2 หลัก + blank space
        {
            str2++;
            str2++;
            str2++;
        }
        */

        // printf("num %d\n", num[j]);
        j++;
    }

    j = 0;
    while (j < i)
    {
        // Generate new node
        newNode = (node *)malloc(sizeof(node));
        newNode->data = num[j]; // define data
        newNode->next = NULL;   // no link

        // Link new node to the linked list
        if (*start == NULL)
            *start = newNode; // if first node, link from header
        else
            ptr->next = newNode; // if latter node, link from current
        ptr = newNode;           // move current to new node
        j++;
    }
}


void revertList(node **start, int startPoint, int endPoint)
{
    node *ptr = *start, *swap;
    int swapStart = 0, i = 1, swapEnd = 0;
    int count = 0;
    while (startPoint + count != endPoint - count)
    {
        ptr = *start;
        swap = *start;
        i = 1;
        while (i <= endPoint - count)
        {
            
            if (i == startPoint + count)
            { 
                swapStart = swap->data;
            }
            else if (i == endPoint - count)
            {
                swapEnd = swap->data;
            }
            swap = swap->next;
            i++;
        }


        i = 1;
        while (i <= endPoint - count)
        {
            if (i == startPoint + count)
            {
                ptr->data = swapEnd;
            }
            else if (i == endPoint - count)
            {
                ptr->data = swapStart;
            }
            ptr = ptr->next;
            i++;
        }
        count++;
        
    }
}


void display(node *start)
{
    node *ptr = start; // start
    // printf("Data in the list: ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data); // print data of current node
        ptr = ptr->next;          // move current to the next node
    }
    printf("\n");
}

int main()
{
    int startPoint, endPoint;
    node *ll;
    createList(&ll);
    scanf("%d %d", &startPoint, &endPoint);
    revertList(&ll, startPoint, endPoint);
    display(ll);
    return 0;
}