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

// add move next of node befor node that cut to next node
// change endIndex to endIndex - 1
// new loop after found node that want to move begin from star
// 3 2 2 3 2 1 END
int palindromeCheck(node **start, int endIndex)
{
    node *ptrEnd, *ptrStart = *start;
    int startIndex = 0;
    int index[5];
    int j = 0; // for check index 
    int i = 0, startCheck = 0, endCheck = 0;
    int min = 0; 
    int count = 0;\
    int endIndexNew = endIndex - 1;
    for (int n = 0; n < 5; n++)
    {
        index[n] = -1;
    }

    // case 1 END
    if (ptrStart->next == NULL)
    {
        printf("None\n");
        return 0;
    }

    // case 7 8 8 7 8
    while ((startIndex + count != endIndexNew - count) && (startIndex + count < endIndexNew - count)) 
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

        //printf("startData %d endData %d\n", ptrStart->data, ptrEnd->data);
        if (ptrStart->data != ptrEnd->data)
        {
            break;
            count++;
        }
        count++;
    }

    count = count - 1; // want count before end loop
    if (startIndex + count == endIndexNew - count - 1) // -1  is check ตัวติดกัน
    {
        printf("%d\n", endIndex);
        return 0;
    }



    count = 0;
    while ((startIndex + count != endIndex - count) && (startIndex + count < endIndex - count)) // use in case เงื่อนไขแรกใช้ไม่ได้
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

            // 5 2 3 5
            // 5 4 2 1 4 5
            // in case startIndex and endIndex ต่อกัน
            if (startIndex + count == endIndex - count - 1)
            {
                //printf("In loop\n");
                ptrStart = *start;
                while (i < startIndex + count - 1)
                {
                    ptrStart = ptrStart->next;
                    i++;
                }
                if (i == 0) // check 1 2 END
                {
                    index[j] = startIndex + count;
                    break;
                }
                ptrStart->next = ptrStart->next->next->next;
                index[j] = startIndex + count;
                break;
            }


            // keep data for check  
            //endIndex check with startIndex + 1 and startIndex check with endIndex - 1
            startCheck = ptrStart->data;
            endCheck = ptrEnd->data;


            ptrStart = ptrStart->next; // for check with endCheck
            ptrEnd = *start; // for loop until before endIndex that not equal to startIndex
            while (i < endIndex - count - 1) // for check with startCheck
            {
                ptrEnd = ptrEnd->next;
                i++;
            }

            i = 0;
            // check startIndex with endIndex -1
            if (startCheck != ptrEnd->data)
            {
                ptrStart = *start;
                

                i = 0;
                // move node before ptrStart node to node next to ptrStart node
                while (i < startIndex + count - 1)
                {
                    ptrStart = ptrStart->next;
                    i++;
                }

                ptrStart->next = ptrStart->next->next;
                index[j] = startIndex + count;
                j++;
                endIndex = endIndex - 1;
                count = 0;
                // printf("starIndex %d", startIndex + count);
            }
            else if (endCheck != ptrStart->data) // check endIndex with startIndex + 1
            {
                ptrEnd = *start;
                // move node before ptrEnd node to node next to ptrEnd node
                while (i < endIndex - count - 1)
                {
                    ptrEnd = ptrEnd->next;
                    i++;
                }
                // printf("endIndex %d", endIndex - count);
                ptrEnd->next = ptrEnd->next->next;
                index[j] = endIndex - count;
                j++;
                endIndex = endIndex - 1;
                count = 0;
            }
            startIndex = 0;
        }
        if (i == 0) // if node is not removed
        {
            count++;
        }
    }

    // printf("before check min index\n");
    //  check min index
    j = 0;
    if (index[j] == -1)
    {
        printf("None\n");
    }
    else
    {
        min = index[j];
        while (index[j] != -1)
        {
            if (index[j] < min)
            {
                min = index[j];
            }
            j++;
        }
        printf("%d", min);
    }
}

int main()
{
    // 7878
    int i;
    node *ll;
    i = createList(&ll);
    if (i == -1)
    {
        return 0;
    }
    palindromeCheck(&ll, i);

    return 0;
}