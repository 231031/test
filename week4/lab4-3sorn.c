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

            while (ptr != NULL && priorVal <= ptr->prior) 
            {
               preptr = ptr;
               ptr = ptr->next;
            }
            if (preptr == *front && priorVal > preptr->prior) 
            {
               newNode->next = *front;
               *front = newNode;
               maxPrior = newNode->prior;
            }
            else
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
