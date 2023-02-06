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
    return i-1;
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

int palindromeCheck(node **start, int endIndex)
{
    node *ptrEnd, *ptrStart;
    int startIndex = 0;
    int i = 0, startCheck = 0, endCheck = 0;
    int count = 0;
    //printf("endIndex = %d\n", endIndex);
    while (startIndex + count != endIndex - count && startIndex + count < endIndex - count)
    {
        ptrEnd = *start;
        ptrStart = *start;
        i = 0;
        // find endIndex in Linked List
        while (i < endIndex - count)
        {
            ptrEnd = ptrEnd->next;
            i++;
        }

        i = 0;
        // find startIndex in linked list
        while (i < startIndex + count)
        {
            ptrStart = ptrStart->next;
            i++;
        }

        i = 0;
        if (ptrStart->data != ptrEnd->data)
        {

            //printf("%d %d\n", ptrStart->data, ptrEnd->data);
            startCheck = ptrStart->data;
            endCheck = ptrEnd->data;
            ptrStart = ptrStart->next;
            ptrEnd = *start;
            while (i < endIndex - count - 1)
            {
                ptrEnd = ptrEnd->next;
                i++;
            }

            // check startIndex with endIndex -1
            if (startCheck != ptrEnd->data)
            {
                printf("%d", startIndex + count);\
                return 0;
            }
            else if (endCheck != ptrStart->data) // check endIndex with startIndex + 1
            {
                printf("%d", endIndex - count);
                return 0;
            }
        }
        count++;
    }
    printf("None\n");
}

int main()
{
    int i;
    node *ll;
    i = createList(&ll);
    palindromeCheck(&ll, i);

    return 0;
}