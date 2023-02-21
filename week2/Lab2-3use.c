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
    int num;
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

    str2 = str;
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
    return i - 1;
}


// add move next of node before node that cut to next node
// change endIndex to endIndex - 1
// new loop after found node that want to move begin from star
// 5 6 7 8 7 END
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
    while (((startIndex + count != endIndexNew - count) && (endIndexNew != endIndex) && checkNew == 0) && 
    ((startIndex + count < endIndexNew - count) && (endIndexNew != endIndex) && checkNew == 0))
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
            // in case startIndex and endIndex ต่อกัน เช็คตัวที่ต่อกัน
            if (startIndex + count == endIndex - count - 1)// 5 2 3 5 or 5 4 2 1 4 5
            {
                ptrStart = *start;
                while (i < startIndex + count - 1)
                {
                    ptrStart = ptrStart->next;
                    i++;
                }
                // เอาออก
                /*
                if (i == 0) // check 1 2 END
                {
                    index[j] = startIndex + count;
                    break;
                }
                */
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
            while (i < endIndex - count - 1) // for check with startCheck
            {
                ptrEnd = ptrEnd->next;
                i++;
            }

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