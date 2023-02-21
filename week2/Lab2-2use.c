#include <stdio.h>
#include <stdlib.h>

// Structure of list node
typedef struct node
{
    int data;
    struct node *next;
} node;

int createList(node **start)
{
    int i = 0, j = 0;
    int num = 0;
    char str[50];
    char *str2;
    char temp;
    node *newNode, *ptr;
    *start = NULL;
    str2 = str;

    // user input
    fgets(str, 50, stdin);
    if (str[0] == '\n')
    {
        printf("\n");
        return -1;
    }

    // created Link list
    while (1)
    {
        sscanf(str2, "%d", &num);
        while (*str2 != ' ' && *str2 != 'E')
        {
            str2++;
        }

        // Generate new node
        newNode = (node *)malloc(sizeof(node));
        newNode->data = num; // define data
        newNode->next = NULL;   // no link

        // Link new node to the linked list
        if (*start == NULL)
            *start = newNode; // if first node, link from header
        else
            ptr->next = newNode; // if latter node, link from current
        ptr = newNode;           // move current to new node

        str2++;                  // skip blank space
        if (*str2 == 'E')
        {
            break;
        }
    }

    return 0;
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
    int check = 0;
    node *ll;
    check = createList(&ll);
    if (check == -1)
    {
        return 0;
    }
    scanf("%d %d", &startPoint, &endPoint);
    revertList(&ll, startPoint, endPoint);
    display(ll);
    return 0;
}