#include <stdio.h>
#include <stdlib.h>

// Structure of list node
typedef struct node
{
    int data;
    struct node *next;
} node;

// Create a linked list
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
    
    if (str[0] == 'E') // check END
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
        else if (num[j] >= 1) //เลข 1 หลัก + blank space
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

    return 0;
}

int check(node **start)
{
    int checkStart = 0;
    int num = 0;
    node *preptr = *start, *midptr, *ptr;
    midptr = preptr->next;
    if (midptr == NULL)
    {
        return 0;
    }
    ptr = midptr->next;

    // find new start node ที่ตัดตัวซ้ำออกแล้ว
    while (ptr != NULL)
    {
        if ((preptr->data != midptr->data && midptr->data != ptr->data)) // ถ้า 3 ตัวที่ติดกันไม่เท่ากันแล้วออกจาก loop
        {
            break;
        }
        else if (checkStart == 0 && preptr->data != midptr->data) // ใช้ start อันเดิม
        {
            break;
        }

        if (preptr->data == midptr->data) // ถ้าตัวหน้ากับตัวกลางเท่ากัน
        {
            checkStart++;
            free(preptr);
            preptr = midptr;
            midptr = midptr->next;

            ptr = midptr->next;
        }
        else if (midptr->data == ptr->data) // ถ้าตัวกลางกับตัวหลังเท่ากัน
        {
            checkStart++;
            free(preptr);
            preptr = midptr;
            midptr = midptr->next;

            ptr = midptr->next;
        }
    }

    if (midptr->next == NULL && preptr->data == midptr->data) // ถ้าตัวสุดท้ายกับตัวก่อนสุดเท่ากัน
    {
        printf("None\n");
        return -1;
    }

    if (checkStart != 0) // ถ้าเปลี่ยน start
    {
        *start = midptr;
    }
    //printf("start %d\n", (*start)->data);

    // new link
    // เช็คเลขที่ซ้ำ
    preptr = *start;
    midptr = preptr->next;
    if (midptr == NULL) //ถ้าเหลือ start ตัวเดียว ออกจาก function
    {
        return 0;
    }
    ptr = midptr->next;

    // เริ่มเช็คเลขซ้ำ
    while (ptr != NULL && midptr != NULL)
    {
        if (midptr->data == ptr->data) // ถ้าเจอตัวซ้ำ
        {
            while (midptr->data == ptr->data) // วนจนถึงตัวที่ไม่ซ้ำกัน
            {
                ptr = ptr->next;
                if (ptr == NULL)
                {
                    preptr->next = NULL;
                    num = -2;
                    break;
                }
            }
            if (num == -2)
            {
                break;
            }
            if (ptr->next == NULL) //ถ้า ptr ถึงตัวสุดท้ายแล้ว
            {
                preptr->next = ptr;
                break;
            }
            if (ptr->data != ptr->next->data) // เช็คเลขที่ไม่ซ้ำกับ preptr กับ เลขตัวถัดไปของเลขที่ไม่ซ้ำ
            {
                preptr->next = ptr; // link ไปเลขที่ไม่ซ้ำ
                preptr = ptr;
                midptr = preptr->next;
                if (midptr == NULL)
                {
                    break;
                }
                ptr = midptr->next;
            }
            else // เลื่อนไปตัวถัดถัดไป
            {
                if (ptr->next->next == NULL)
                {
                    preptr->next = NULL;
                    return 0;
                }
                midptr = ptr->next->next;
                ptr = midptr->next;
            }
            
        }
        else // preptr ไม่ซ้ำกับ midptr และ midptr ไม่ซ้ำกับ ptr
        {
            preptr = preptr->next;
            midptr = midptr->next;
            ptr = ptr->next;

        }
    }
    return 0;
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
    int checkNum = 0;
    int checkNum2 = 0;
    node *ll;
    checkNum2 = createList(&ll);
    if (checkNum2 == -1)
    {
        return 0;
    }
    checkNum = check(&ll);
    if (checkNum != 0)
    {
        return 0;
    }
    display(ll);

    return 0;
}