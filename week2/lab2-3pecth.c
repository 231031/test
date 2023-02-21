#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//  สร้าง struct node เพื่อใช้เป็น node ของ linked list 
typedef  struct node
{
	int data;               // เก็บข้อมูลแบบ integer
	struct node *next;      // เก็บ ตำแหน่งที่อยู่ของ node ถัดไป
}node;      // ใช้ typedef กำหนดให้เป็น node

// สำหรับสร้างโหนดใหม่ของ linked list
void createNode(int data, node **Node)
{
    // ใช้ malloc เพื่อจองพื้นที่ในหน่วยความจำสำหรับโหนด
	node *new = (node*)malloc(sizeof(node));
	new->data = data;   // กำหนดให้ data ของโหนดเท่ากับข้อมูลที่รับเข้ามา
	new->next = NULL;   // กำหนดให้ next ของโหนดเป็น NULL เพื่อให้โหนดใหม่นี้เป็นโหนดสุดท้ายใน linked list
	*Node = new;
}
// ใช้สำหรับสร้าง linked list โดยเพิ่ม node ต่อท้ายของ linked list  จนกว่าผู้ใช้จะป้อนคำว่า "END" 
void makeListAddback(node **head)
{
	int data;
	char buffer[128];
	node *ptr, *newNode;
	while(1)
	{	
        // รับค่าเข้ามาจากผู้ใช้ผ่านทางคีย์บอร์ด ด้วยฟังก์ชัน scanf
		scanf("%s", buffer);
		//printf("%s\n", buffer);
        // ตรวจสอบว่าคำใน buffer เป็น "END" หรือไม่ ถ้าใช้ให้เลิกการรับค่าและสิ้นสุดการทำงาน
		if(strcmp(buffer, "END") == 0)
		{
			break;
		}
		else
		{
  		data = atoi(buffer);
			//printf("%d\n", data);
            //สร้าง node ใหม่โดยใช้ฟังก์ชัน createNode 
			createNode(data, &newNode);
            // ตรวจสอบว่า linked list มี node หรือยัง ถ้าไม่มีให้กำหนด pointer head ชี้ไปยัง node ใหม่
        
			if(*head == NULL)
			{
				*head = newNode;
			}
            // ถ้ามี node อยู่ให้ pointer ptr ชี้ไปยัง node ตัวสุดท้ายของ linked list 
            // และกำหนด pointer next ของ node ตัวสุดท้ายนั้นชี้ไปยัง node ใหม่ที่สร้างไว้ใหม่
			else
			{
				ptr->next = newNode;
			}
			ptr = newNode;
		}			
	}
}

// function นับจำนวน node ใน linked list
int countNodes(node *head) 
{
    // กำหนดให้ curr เท่ากับ head วน loop นับจำนวน node
  int count = 0;
  node *curr = head;
  while (curr != NULL) 
	{
    count++;
    curr = curr->next;
  }
  return count;
}

void display(node *start)//ไม่ได้ใช้
{
  node *ptr = start;
  printf("Data in the list: ");
  while(ptr != NULL)
  {
    printf("%d ",ptr->data);
    ptr = ptr->next;            
  }
}

// function สร้างตัวซ้ำ 
node *duplicate(node *head)
{
    // ถ้า linked list ไม่มีข้อมูลอยู่ return NULL
	if(head == NULL)
	{
		return NULL;
	}
    // ถ้ามี เอาข้อมูลของ head ไปสร้าง node ใหม่ และ link ไป node ใหม่
	else
	{
		node *newNode;
		createNode(head->data, &newNode);
		newNode->next = duplicate(head->next);
		return newNode;
	}
}

// function กลับด้าน linkeed list
void reverse(node **head)
{
  // กำหนด pointer ตัวแรก prev ให้เป็น NULL และ pointer ตัวปัจจุบัน curr ให้ชี้ไปที่โหนดแรกของ linked list คือ head
  node *prev = NULL;
  node *curr = *head;
  node *next;
  while(curr != NULL)
  {
    // ทำการสลับ pointer ของ curr ให้ชี้ไปยัง prev แทน ด้วยการกำหนด curr->next เป็น prev 
    next = curr->next;
    curr->next = prev;
    // สลับตำแหน่งของ prev และ curr ด้วยการกำหนด prev = curr และ curr = next 
    prev = curr;
    curr = next;
  }
//   กำหนด node แรกเป็น prev
  *head = prev;
}

// ตรวจสอบว่า linked list เป็น palindrome หรือไม่ 
int isPalindrome(node *A)//return 0:not_palindrome, 1:palindrome
{
    // สร้าง linked list ใหม่ B ที่เหมือน A โดยใช้ฟังก์ชัน duplicate 
	node *B = duplicate(A);
    // กลับด้าน linked list B ด้วยฟังก์ชัน reverse
	reverse(&B);
    // ตรวจสอบว่าแต่ละโหนดของ A และ B มีค่าของ data เท่ากันหรือไม่ 
    // หากไม่เท่ากันในโหนดใด ๆ ฟังก์ชันจะ return ค่า 0 แสดงว่า linked list ไม่เป็น palindrome 
    // แต่หากเท่ากันทั้งหมดจนถึงโหนดสุดท้าย ฟังก์ชันจะ return ค่า 1 แสดงว่า linked list เป็น palindrome
	node *a = A, *b = B;
    // ถ้า a และ b ไม่มีข้อมูลจะ return 0
	if(a == NULL || b == NULL)
	{
		return 0;
	}
	else
	{
        // ทำการเปรียบเทียบค่าของ data ของโหนดที่ชี้โดย a และ b ในแต่ละรอบของลูป while 
		while(a && b)
		{
            // หากค่าของ data เท่ากัน a และ b จะทำการเลื่อนไปยังโหนดต่อไปของ A และ B 
			if(a->data == b->data)
			{
				a = a->next;
				b = b->next;
			}
            // ถ้าค่าของ data ไม่เท่ากันในโหนดใด ๆ ฟังก์ชันจะ return ค่า 0 และไม่ต้องเปรียบเทียบโหนดที่เหลือของ A และ B 
            // เนื่องจาก linked list ไม่เป็น palindrome 
			else
			{
				return 0;
			}
		}
	}
    // ฟังก์ชันจะ return ค่า 1 แสดงว่า linked list เป็น palindrome 
	return 1;
}

void delNode(int index, node **head)//&node[index] = &node[0] + sizeof(node)*(index-0)
{
    // สร้าง pointer ชื่อ curr และ prev และกำหนดให้ curr เป็น head และ prev เป็น NULL
	node *curr = *head;
  node *prev = NULL;

    // ตรวจสอบว่า linked list นี้ว่างหรือไม่ หากว่างให้จบการทำงานของฟังก์ชัน
  if(curr == NULL) 
	{
		return;
	}
    // ตรวจสอบว่า index ที่ระบุอยู่ในช่วงที่ถูกต้องหรือไม่ ถ้าไม่ใช่ให้จบการทำงานของฟังก์ชัน
  if(curr == NULL || index < 0 || index > countNodes(*head)-1) 
	{
		return;
	}
// หาก index เท่ากับ 0 ให้ลบ node ที่อยู่ที่เริ่มต้นของ linked list โดยกำหนด head ใหม่เป็น node ถัดไปของ curr และลบ curr ออกจากหน่วยความจำ
  if(index == 0) //delete begin
	{
    *head = curr->next;
    free(curr);
    return;
  }
// หาก index ไม่ใช่ 0 ให้วน loop จนกว่า curr จะเป็น NULL หรือเจอ node ที่มีดัชนีเท่ากับ index
// หลังจากวน loop แล้ว ถ้า curr เป็น NULL แสดงว่าไม่เจอ node ที่มีดัชนีเท่ากับ index ให้จบการทำงานของฟังก์ชัน
  for(int i = 0; curr != NULL && i < index; i++) 
	{
    prev = curr;
    curr = curr->next;
  }
// ถ้าเจอnnondeที่มีดัชนีเท่ากับ index ให้nodeก่อน curr ชี้ไปยังnodeถัดไปของ curr และลบ curr ออกจากหน่วยความจำ
  prev->next = curr->next;
  free(curr);
}

int main(void) 
{
    // สร้าง linked list โดยใช้ฟังก์ชัน makeListAddback 
	int index = 0;
    node *head = NULL;
	makeListAddback(&head);
    // เรียกใช้ฟังก์ชัน isPalindrome เพื่อตรวจสอบว่าลิสต์ที่สร้างขึ้นเป็น Palindrome หรือไม่ 
    // ถ้าเป็น Palindrome โปรแกรมจะแสดงข้อความ "None" และจบการทำงาน 
	if(isPalindrome(head) == 1)
	{
		printf("None");
		return 0;
	}
    // ถ้าไม่เป็น Palindrome โปรแกรมจะเข้าสู่ลูป while 
	else
	{
		while(1)
		{
            // ทำการคัดลอกลิสต์ที่เก็บไว้ในตัวแปร head ไปเก็บไว้ในตัวแปร copyHead 
			node *copyHead = duplicate(head);
            // ลบ node ออกจาก copyHead ด้วยฟังก์ชัน delNode
			delNode(index, &copyHead);
            // ตรวจสอบว่า copyHead เป็น Palindrome หรือไม่ ถ้าเป็น Palindrome โปรแกรมจะแสดงค่า index และจบการทำงาน 
			int check = isPalindrome(copyHead);
			if(check == 1)
			{
				printf("%d", index);
				return 0;
			}
            // ถ้าไม่เป็น Palindrome โปรแกรมจะเช็คว่า index มีค่ามากกว่าจำนวน node ในลิสต์หรือไม่ ถ้ามากกว่าโปรแกรมจะแสดงข้อความ "None" และจบการทำงาน
			else if(index > countNodes(head))
			{
				printf("None");
				return 0;
			}
            // ถ้าน้อยกว่าโปรแกรมจะเพิ่มค่า index และเริ่ม loop ใหม่
			else
			{
				index++;
				continue;
			}
		}
	}
}