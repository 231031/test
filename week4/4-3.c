#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
   char data[128];
   int prior;
   struct node *next;
};

int createList(struct node **front);
int deQ(struct node **head, char *dataOut);
void getInput(char *destination, int quota, FILE *stream);

int main()
{
   struct node *head = NULL;
   char inputBuffer[256];
   char outputStream[256];
   int numOfDeQ = 0, i = 0, deQretVal = 0;
   createList(&head);
   getInput(inputBuffer, 256, stdin);
   numOfDeQ = atoi(inputBuffer);
   for (i = 0; i < numOfDeQ; i++)
   {
      deQretVal = deQ(&head, outputStream);
      printf("%s ", outputStream);
      if (deQretVal == -1)
         break;
   }
   return 0;
}


int createList(struct node **front)
{
   char buffer[256];
   char *tokenData, *tokenPrior;
   struct node *newNode = NULL, *ptr = *front, *preptr = *front;
   int dataFlag = 0, priorFlag = 0, priorVal = 0, maxPrior = 0;
   fgets(buffer, 256, stdin);
   if (buffer[strlen(buffer) - 1] == '\n')
      buffer[strlen(buffer) - 1] = '\0';

   tokenData = strtok(buffer, " ");
   dataFlag = 1;


   while (tokenData != NULL)
   {
      // have to get priorVal and tokenData to create newNode so check dataFlag and priorFlag
      // ทุกครั้งที่วนลูปจะมีการรับ tokenData และ dataFlag จะกลายเป็น 1 วนลูปอีกรอบมารับ priorVal และ priorFlag จะกลายเป็น 1 
      // ทั้งคู่กลายเป็น 1 จะเข้าเงื่อนไข if เพื่อสร้าง newNode 
      // ตอนสร้าง newNode ถ้า front ไม่เป็น NULL จะ while loop เพื่อหาตำแหน่งที่เหมาะสมที่จะเพิ่ม newNode เข้าไป
      if (dataFlag == 1)
      {
         tokenPrior = strtok(NULL, " ");
         priorVal = atoi(tokenPrior);
         priorFlag = 1;
      }
      else
      {
         tokenData = strtok(NULL, " ");
         dataFlag = 1;
      }
      if (dataFlag == 1 && priorFlag == 1)
      {
         newNode = (struct node *)calloc(1, sizeof(struct node));
         strcpy(newNode->data, tokenData);
         newNode->prior = priorVal;
         newNode->next = NULL;
         if (*front == NULL)
         {
            *front = newNode;
            ptr = *front;
            maxPrior = priorVal;
         }
         else
         {
            if (priorVal == -1)
            {
               priorVal = maxPrior + 1;
               newNode->prior = priorVal;
            }

            while (ptr != NULL && priorVal <= ptr->prior) // while loop จนกว่าจะเจอ node ที่ priorVal มากกว่า priorValที่ได้มาจาก if else ข้างบน หรือจนกว่าจะเจอ node ที่เป็น NULL
            {
               preptr = ptr;
               ptr = ptr->next;
            }
            if (preptr == *front && priorVal > preptr->prior) // check if priorVal มากกว่าของ front ก็จะเปลี่ยน newNode อันนั้นเป็น front แล้วก็เปลี่ยน maxPrior
            {
               newNode->next = *front;
               *front = newNode;
               maxPrior = newNode->prior;
            }
            else // ไม่เปลี่ยน maxPrior เชื่อม next ของ node ที่วนลูปเจอกับ newNode (แทรก newNode ระหว่าง node ที่ priorVal น้อยกว่าหรือเท่ากับ กับ node ที่ priorVal มากกว่า) 
            //เชื่อม node ที่น้อยหว่าหรือเท่ากับ กับ newNode และเชื่อม next ของ newNode กับ node ที่เจอจากการ while loop ว่า priorVal มากกว่า
            {
               preptr->next = newNode;
               newNode->next = ptr;
            }
         }
         ptr = *front;
         preptr = ptr;
         dataFlag = 0;
         priorFlag = 0;
      }
   }
}

int deQ(struct node **head, char *dataOut)
{
   struct node *ptr = *head;
   if (*head == NULL)
   {
      strcpy(dataOut, "None");
      return -1;
   }
   strcpy(dataOut, ptr->data);
   if (ptr->next == NULL)
   {
      free(ptr);
      *head = NULL;
   }
   else
   {
      *head = (*head)->next;
      free(ptr);
   }
   return 1;
}

void getInput(char *destination, int quota, FILE *stream)
{
   fgets(destination, quota, stdin);
   if (destination[strlen(destination) - 1] == '\n')
   {
      destination[strlen(destination) - 1] = '\0';
   }
}
