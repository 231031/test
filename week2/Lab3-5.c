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

void loopFindIndex(node *ptr, int index)
{
    int i = 0;
    while (i < index)
    {
        ptr = ptr->next;
        i++;
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

// add move next of node before node that cut to next node
// change endIndex to endIndex - 1
// new loop after found node that want to move begin from star
// 5 6 7 8 7 END
int palindromeCheck(node **start, int endIndex)
{
    node *ptrEnd = *start, *ptrStart = *start;
    int startIndex = 0;
    int index[5];
    int j = 0; // for check index
    int i = 0, startCheck = 0, endCheck = 0;
    int min = 0;
    int count = 0;
    int endIndexNew = 0;
    int checkNew = 0;
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

    // case cannot make palindrome
    // ถ้าไม่มีเลขที่ซ้ำกันเลยจะไม่เป็น palindrome
    // 1 2 3 END
    // 5 6 7 8 7 END
    // check ptrStart with ptrEnd ทุกตัวที่อยู่หลังจาก ptrStart นั้น
    ptrEnd = ptrEnd->next;
    while (ptrStart != NULL)
    {
        while (ptrEnd != NULL)
        {
            if (ptrStart->data == ptrEnd->data)
            {
                checkNew++;
                break;
            }
            ptrEnd = ptrEnd->next;
        }
        if (checkNew != 0)
        {
            break;
        }
        ptrStart = ptrStart->next;
        if (ptrStart == NULL)
        {
            break;
        }
        ptrEnd = ptrStart->next;
    }
    if (checkNew == 0)
    {
        printf("None\n");
        return 0;
    }

    // 3 2 3 2 3 3 1 END
    // case 7 8 8 7 8
    ptrEnd = *start;
    checkNew = 0;
    while (ptrStart->data != ptrEnd->data || endIndexNew <= endIndex / 2)
    {
        ptrEnd = ptrEnd->next;
        endIndexNew++;
        if (endIndexNew > endIndex) // checkNew it can end loop by itself
        {
            checkNew++;
            break;
        }
    }
    // printf("endIndexNew = %d\n", endIndexNew);

    // endIndexNew != endIndex check case that maybe None
    while (((startIndex + count != endIndexNew - count) && (endIndexNew != endIndex) && checkNew == 0) && ((startIndex + count < endIndexNew - count) && (endIndexNew != endIndex) && checkNew == 0))
    {
        ptrStart = *start;
        ptrEnd = *start;
        i = 0;
        // change from while loop
        loopFindIndex(ptrStart, startIndex + count); 
        loopFindIndex(ptrEnd, endIndexNew - count);

        if (ptrStart->data != ptrEnd->data)
        {
            break;
        }
        count++;
    }

    // เงื่อนไขแรกใช้ได้เลย
    //  เงื่อนไขที่สอง count จะโดนบวกก่อนออกจาก loop จึงต้องลบ count ออก 1 ด้วย
    //  end loop by same Index and or loop by index ห่างกัน 1
    if ((startIndex + count == endIndexNew - count) || (startIndex + (count - 1) == endIndexNew - (count - 1) - 1)) // delete count 1
    {
        printf("%d\n", endIndexNew + 1); // remove index next to endIndexNew
        return 0;
    }

    // case ที่เหลือจากข้างบน
    count = 0;
    while ((startIndex + count != endIndex - count) && (startIndex + count < endIndex - count)) // use in case เงื่อนไขแรกใช้ไม่ได้
    {
        ptrEnd = *start;
        ptrStart = *start;
        i = 0;
        // find endIndex in Linked List

        // change from while loop
        loopFindIndex(ptrEnd, endIndex - count);
        loopFindIndex(ptrStart, startIndex + count);

        i = 0;
        if (ptrStart->data != ptrEnd->data)
        {

            // 5 2 3 5
            // 5 4 2 1 4 5
            // in case startIndex and endIndex ต่อกัน
            // เช็คตัวที่ต่อกัน
            if (startIndex + count == endIndex - count - 1)
            {
                // printf("In loop\n");
                ptrStart = *start;

                // change from while loop
                loopFindIndex(ptrStart, startIndex + count - 1);

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
            // endIndex check with startIndex + 1 and startIndex check with endIndex - 1
            startCheck = ptrStart->data;
            endCheck = ptrEnd->data;

            ptrStart = ptrStart->next;       // for check with endCheck
            ptrEnd = *start;                 // for loop until before endIndex that not equal to startIndex

            // change from while loop
            loopFindIndex(ptrEnd, endIndex - count - 1); // for check with startCheck

            i = 0;
            // check startIndex with endIndex -1
            if (startCheck != ptrEnd->data)
            {
                if (endCheck != ptrStart->data) // add check case 3 4 5 6 5 4 7 END
                {
                    printf("%d\n", startIndex + count);
                    return 0;
                }
                ptrStart = *start;

                i = 0;
                // move node before ptrStart node to node next to ptrStart node
                // change from while loop
                loopFindIndex(ptrStart, startIndex + count -1);

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
                // change from while loop
                loopFindIndex(ptrEnd, endIndex - count - 1);

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
        // printf("index[0] = %d\n",index[0]);
        // printf("index[1] = %d\n",index[1]);
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