#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100000//กำหนดค่า max ของ stack เป็น 100000

typedef struct Node {//สร้าง struct ชื่อ Node ซึ่งจะเก็บ array char data ขนาด 10 และตำแหน่งของ Node ถัดไป
  char data[10];
  struct Node *next;
}Node;

//สร้างฟังก์ชันชื่อ delete_N เพื่อใช้ในการลบขึ้นบรรทัดที่ต่อท้ายข้อมูล
void delete_N(char *str) {//รับข้อมูลเป็น string จากผู้ใช้
  if (str[strlen(str) - 1] == '\n') {//ถ้าข้อมูลตัวสุดท้ายเป็นขึ้นบรรทัดใหม่ จะให้ข้อมูลตัวสุดท้ายเป็นค่าว่าง
    str[strlen(str) - 1] = '\0';
  }
}
Node* top = NULL;//ให้ตำแหน่งของ node top เป็น NULL

//สร้างฟังก์ชันชื่อ isEmpty เพื่อใช้ในการเช็คว่า linked stack ว่างไหม
int isEmpty(){
  if(top == NULL)//ถ้า top เท่ากับ NULL แสดงว่าว่างจะคืนค่า 1
    return 1;
  else//ถ้าไม้ว่างจะคืนค่า 0
    return 0;
}

//สร้างฟังก์ชันชื่อ push เพื่อใช้ในการนำข้อมูลไปเก็บไว้ใน linked stack
void push(int* k){//รับค่ามาเป็นตำแหน่งของตัวแปรชนิด int
  char buffer[MAX];//สร้างตัวแปรไว้เก็บข้อมูลจากผู้ใช้
  fgets(buffer,MAX,stdin);//รับข้อมูลจากผู้ใช้
  delete_N(buffer);//เรียกใช้ฟังก์ชัน delete_N เพื่อลบขึ้นบรรทัดที่ต่อท้ายข้อมูล
  if(strcmp("\0",buffer)==0){//ถ้าไม่มีข้อมูลในstack จะแสดง None และออกจากฟังก์ชัน
    printf("None");
    exit(1);
  }
  char* num = strtok(buffer, " ");//แบ่งข้อมูลที่รับมาโดยใช้เว้นวรรคแล้วนำไปเก็บไว้ในตัวแปร num
  while(num != NULL){//ใช้ while loop จนกว่าจะไม่มีข้อมูลให้เพิ่มใน stack
    Node* newNode = (Node*)malloc(sizeof(Node));//สร้าง Node ชื่อว่า newNode และทำการจองพื้นที่
    if(newNode == NULL){//ถ้าม่มีข้อมูลใน newNode จะแสดง None
      printf("None");
    }
    strcpy(newNode->data, num);//นำข้อมูลแต่ละตัวมาเก็บไว้ใน data ของ newNode
    newNode->next= NULL;//ให้ตำแหน่งของ node ถัดไปเป็น NULL
    newNode->next = top;//ให้ตำแหน่งของ newNodenode ถัดไปเป็น top
     
    top = newNode; //ให้ top เป็น node ล่าสุดที่พึ่งสร้าง
    (*k)++; //บวกค่า k ทุกครั้งที่วน loop
    num = strtok(NULL, " ");//ให้ข้อมูล num เป็นค่าหลังเว้นวรรค
  }
}

//สร้างฟังก์ชัน pop เพื่อนำข้อมูลออกจาก linked stack
void pop(char* temp_data){
  Node* temp;
  temp = top;
  if(isEmpty()){//เรียกใช้ฟังก์ชัน isEmpty เพื่อเช็คว่า linked stack ว่างไหม ถ้าว่างจะแสดง None
    printf("None");
  }

  strcpy(temp_data, top->data);//นำตัวแปร temp_data มาเก็บข้อมูลตัวล่าสุด
  top = top->next;
  free(temp);

}

int main(void) {

  int count=0,Input;
  char *str;
  push(&count);
  scanf("%d",&Input);//รับจำนวนที่ต้องการนำข้อมูลออก

  if(Input <= count){//ถ้าจำนวนที่ต้องการนำข้อมูลออกน้อยกว่าหรือเท่ากับจำนวนข้อมูล
    for(int i = 0; i< Input;i++){//ใช้ for loop แสดงข้อมูลตามจำนวนที่ต้องการโดยการเรียกใช้ฟังก์ชัน pop
      pop(str);
      printf("%s ", str);
    }
  }

  if(Input > count){//ถ้าจำนวนที่ต้องการนำข้อมูลออกมากกว่าจำนวนข้อมูล
    for(int j = 0;j < count;j++){//ใช้ for loop แสดงข้อมูลตามจำนวนข้อมูลโดยการเรียกใช้ฟังก์ชัน pop
      pop(str);
      printf("%s ", str);
    }
    printf("None");//จากนั้นแสดง None
  }

  return 0;
}