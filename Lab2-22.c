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
    int swapStart = -1, i = 1, swapEnd = -1;
    int count = 0;

    // endPoint is ตำแหน่งสุดท้ายที่ต้องการ revert
    while (startPoint + count != endPoint - count && startPoint + count < endPoint - count)
    {
        ptr = *start;
        swap = *start;
        swapStart = -1;
        swapEnd = -1;
        i = 1;

        // find point that want to revert and get number of point
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

            // swap endPoint with number of startPoint
            if (i == endPoint - count)
            {
                ptr->data = swapStart;
            }

            swap = swap->next;
            ptr = ptr->next;
            i++;
        }

        
        i = 1;
        ptr = *start;

        // swap startPoint with number of endPoint
        while (i <= startPoint + count)
        {
            if (i == startPoint + count)
            {
                ptr->data = swapEnd;
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