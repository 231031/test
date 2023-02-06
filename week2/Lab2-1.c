#include <stdio.h>
#include <stdlib.h>

// Structure of list node
typedef struct node
{
    int data;
    struct node *next;
} node;

// Create a linked list
void createList(node **start)
{
    int i = 0, j = 0;
    int num[20];
    char str[50];
    char *str2;
    char temp;
    node *newNode, *ptr;
    *start = NULL;

    fgets(str, 50, stdin);
    while (str[j] != 'E')
    {
        if (str[j] == ' ') // check blank space
        {
            i++;
        }
        j++;
    }
    //printf("blank space: %d\n", i);
    
    str2 = str;
    j = 0;
    // convert string to array int
    while (j < i)
    {
        sscanf(str2, "%d %c", &num[j], &temp);
        if (num[j] >= 10)
        {
            str2++;
            str2++;
            str2++;
        }
        else
        {
            str2++;
            str2++;
        }
        
        //printf("num %d\n", num[j]);
        j++;
    }

    j = 0;
    while (j < i)
    {
        // Generate new node
        newNode = (node *)malloc(sizeof(node));
        newNode->data = num[j];  // define data
        newNode->next = NULL; // no link

        // Link new node to the linked list
        if (*start == NULL)
            *start = newNode; // if first node, link from header
        else
            ptr->next = newNode; // if latter node, link from current
        ptr = newNode;           // move current to new node
        j++;
    }
}

void createListFromArray(node **start, int num[], int i)
{
    node *newNode, *ptr;
    int n = 0;
    *start = NULL;
    while (n < i)
    {
        // Generate new node

        if (num[n] != -10001)
        {
            newNode = (node *)malloc(sizeof(node));
            newNode->data = num[n]; // define data
            newNode->next = NULL;   // no link
            // Link new node to the linked list
            if (*start == NULL)
                *start = newNode; // if first node, link from header
            else
                ptr->next = newNode; // if latter node, link from current
            ptr = newNode;           // move current to new node
        }
        n++;
    }
}

void display(node *start)
{
    node *ptr = start; // start
    //printf("Data in the list: ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data); // print data of current node
        ptr = ptr->next;          // move current to the next node
    }
    printf("\n");
}

int check(node **start, int num[])
{
    node *ptr = *start;
    node *preptr;
    int i = 0;
    int j = 0;
    int checkNum = 0;
    while (ptr->next != NULL)
    {
        num[i] = ptr->data;
        preptr = ptr;
        ptr = ptr->next;
        i++;
        if (ptr->next == NULL)
        {
            //printf("checking\n");
            num[i] = ptr->data;
            i++;
            break;
        }
        free(preptr);
    }
    checkNum = num[j];

    while (j < i)
    {
        if (num[j] == checkNum && j != 0)
        {
            checkNum = num[j];
            num[j - 1] = -10001;
            num[j] = -10001;
        }
        else
        {
            checkNum = num[j];
        }
        j++;
    }

    j = 0;
    while (j < i)
    {
        if (num[j] != -10001)
        {
            break;
        }
        else if (num[j] == -10001 && j == i - 1) 
        {
            printf("None\n");
            return -1;
        }
        j++;
    }
    return i;
}

int main()
{
    // Write C code here
    int number[20];
    int i = 0;
    node *ll;
    createList(&ll);
    //display(ll);
    i = check(&ll, number);
    if (i == -1)
    {
        return 0;
    }
    createListFromArray(&ll, number, i);
    display(ll);

    return 0;
}