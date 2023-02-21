//  include library ที่จำเป็นในการใช้
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//  สร้าง struct listnode เพื่อใช้เป็น node ของ linked list 
typedef struct listNode 
{
    int data;                   // เก็บข้อมูลแบบ integer
    struct listNode *next;      // เก็บ ตำแหน่งที่อยู่ของ node ถัดไป
}node;  // ใช้ typedef กำหนดให้เป็น node

// สร้าง function เพื่อใช้สร้าง linked list 
void createLinklist(node **start)       // รับ parameter มาเป็น node แรก
{
    char text[20];                      // ประก่าศตัวแปร text รับข้อมูลมาเป็น string
    int num, check;                     // ประกาศตัวแปรประเภท integer ชื่อว่า num, check 
    node *newnode, *ptr;                // สร้าง newnode, ptr
    *start = NULL;                      // set start เท่ากับ NULL เพื่อใช้เป็นตัวแรก

    scanf("%s", &text);                 // รับ input ไปเก็บในตัวแปร text
    check = atoi(text);                 // แปลง ข้อมูลแบบ string ใน text เป็นข้อมูลแบบ integer 

    if (check > 10000 || check < -10000)    // นำค่าตัวแปร check มาเช้ค ถ้ามากกว่า 10000 หรือน้อยกว่า -10000 ให้รับค่าใหม่
    {
        scanf("%s", &text);                 // รับ input ไปเก็บในตัวแปร text อีกครั้ง
    }
    
    while (strcmp(text, "END") != 0)        // strcmp เพือเปรียบเทียบว่า ผู้ใช้กรอกคำว่า END หรือไม่ ถ้าพิมพ์จะ return 0 และไม่เข้า while loop
    {
        num = atoi(text);                       // นำข้อมูลใน text มาเปลี่ยนเป็น integer เก็บไว้ในตัวแปร num 
        newnode = (node*)malloc(sizeof(node));  // จองพื้นที่ของ node
        newnode->data = num;                    // ให้ data ของ newnode เท่ากับ num
        newnode->next = NULL;                   // ให้ next ของ newnode เท่ากับ NULL 

        if (*start == NULL)             // ถ้า start เท่ากับ NULL แสดงว่า ยังไม่มี node อื่น
        {
            *start = newnode;           // set ให้ start = newnode
        }
        else                            // มี node อยู่แล้ว
        {
            ptr->next = newnode;        // ลิ้งค์ไปยัง newnode
        }
        ptr = newnode;                  // เลื่อน ptr ไปยัง newnode
        scanf("%s", &text);             // รับ input ไปเก็บในตัวแปร text อีกครั้ง
    }
}

// function ลบตัวซ้ำ
void deleteDuplicate(node **start)
{
    // ประกาศตัวแปรที่จำเป็น
    node *ptr = *start; 
    node *preptr = NULL; 
    node *temp;

    while (ptr != NULL && ptr->next != NULL) // วน loop check ว่ามี ตำแหน่งที่ ptr อยู่ไม่ใช่ตัวสุดท้าย และไม่มีข้อมูลอยู๋
    {
        if (ptr->data == ptr->next->data) // data ของ ptr = data ของ ptr ตัวถัดไป
        {
            int duplicate = ptr->data; // store ptr->data in duplicate
            while (ptr != NULL && ptr->data == duplicate) // check ว่า data ของ ptr เท่ากับ ตัวแปร duplicate มั้ย
            {
                temp = ptr; //  set temp = ptr
                ptr = ptr->next; // set ptr ให้ขยับไป ptr ตัวหน้า
                free(temp); // delete node temp (จำกัดตัวซ้ำ)
            }

            if (preptr == NULL) // ในกรณีที่เป็นตัวแรก
            {
                *start = ptr;       // ให้ start เท่ากับ ptr
            }
            else
            {
                preptr->next = ptr; // ลิ้ง preptr ไปตัวหน้า
            }
        }
        else // ถ้าไม่ตรงเงื่อนไข if ให้ขยับ preptr และ ptr ไปตัวถัดไป
        {
            preptr = ptr;
            ptr = ptr->next;
        }
    }
}

// function แสดง linked list
void display(node *start)
{
    node *ptr = start;      
    while (ptr != NULL)     // ถ้า ptr มีข้อมูล ไม่ว่างเปล่า ให้แสดงข้อมูลออกมา และขยับ ptr ไปตัวถัดไป
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    
    if (start == NULL)      // ถ้า start เท่ากับ NULL หมายถึง linkeslist ว่างเปล่า ให้แสดงผล None
    {
        printf("None");
    }
}

// function main ไว้เรียกใช้ function ที่สร้างไว้ทั้งหมด
int main()
{
    node *ll;               // สร้าง node ll เพื่อส่งเข้าไปใน function 
    createLinklist(&ll);   
    deleteDuplicate(&ll);
    display(ll);
    return 0;
}