#include<stdio.h>
#include<stdlib.h>

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
    if (str[0] == 'E')
    {
        printf("None\n");
        return -1;
    }
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
    return i - 1;
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

int checkPalindrome(node **start, int endIndex)
{
    int count = 0, i = 0;
    node *ptrStart = *start, *ptrEnd = *start;
    int startIndex = 0;
    int endIndexNew = 0; // endIndexNew = endIndex - 1 not expected case 7 8 8 7 8 9 END
    int loop = 0;

    while (ptrStart->data != ptrEnd->data || endIndexNew <= endIndex/2)
    {   
        ptrEnd = ptrEnd->next;
        endIndexNew++;
    }
    printf("endIndexNew = %d\n", endIndexNew);

    // 7 8 8 7 8
    while ((startIndex + count != endIndexNew - count && loop == 0) && (startIndex + count < endIndexNew - count && loop == 0)) 
    {
        ptrStart = *start;
        ptrEnd = *start;
        i = 0;
        while (i < startIndex + count)
        {
            ptrStart = ptrStart->next;
            ptrEnd = ptrEnd->next;
            i++;
        }

        while (i < endIndexNew - count)
        {
            ptrEnd = ptrEnd->next;
            i++;
        }

        if (ptrStart->data != ptrEnd->data)
        {
            break;
        }
        count++;
    }
    
    //เงื่อนไขแรกใช้ได้เลย
    // เงื่อนไขที่สอง count จะโดนบวกก่อนออกจาก loop จึงต้องลบ count ออก 1 ด้วย
    // end loop by same Index and or loop by index ห่างกัน 1
    if ((startIndex + count == endIndexNew - count && loop == 0)|| (startIndex + (count - 1) == endIndexNew - (count - 1) - 1 && loop == 0)) // delete count 1
    {
        printf("%d\n", endIndexNew + 1); // remove index next to endIndexNew
        return 0;
    }
    else if (loop == 0)
    {
        printf("Error\n");
        loop++;
    }

    /*
    while (startIndex + count != endIndex - count)
    {
        while (ptrStart->data != ptrEnd->data)
        {
            
        }
    }
    */
}


int main()
{
    int endIndex = 0;
    node *ll;
    endIndex = createList(&ll);
    checkPalindrome(&ll, endIndex);
}