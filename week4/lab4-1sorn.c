#define STREAM_LENGHT 4096

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void getInput(char *destination,int quota,FILE *stream);
void dataStreamHandler(char *stream,char (*queue)[STREAM_LENGHT], int *max,int *front,int *rear);
void output(char (*queue)[STREAM_LENGHT],int numOfOut,int *max,int *front,int *rear);

int enQ(char (*queue)[STREAM_LENGHT],char *data,int *max,int *front,int *rear);
int deQ(char (*queue)[STREAM_LENGHT],char *destination,int *max,int *front,int *rear);

int main(){

    char queue[100][STREAM_LENGHT];
    char buffer[STREAM_LENGHT];
    int max = 0, rear = -1, front = -1;
    int numberOfOutput = 0;
    
    //get size of queue <first line input>
    getInput(buffer,STREAM_LENGHT,stdin);
    max = atoi(buffer);
    
    //get first data stream with space seperated <second line input>
    getInput(buffer,STREAM_LENGHT,stdin);
    dataStreamHandler(buffer,queue,&max,&front,&rear);
    
    //output <third line input>
    getInput(buffer,STREAM_LENGHT,stdin);
    numberOfOutput = atoi(buffer);
    output(queue,numberOfOutput,&max,&front,&rear);
    
    //get second data stream with space seperated <fourth line input>
    getInput(buffer,STREAM_LENGHT,stdin);
    dataStreamHandler(buffer,queue,&max,&front,&rear);
    
    //output <fifth line input>
    getInput(buffer,STREAM_LENGHT,stdin);
    numberOfOutput = atoi(buffer);
    output(queue,numberOfOutput,&max,&front,&rear);
    
    return 0;
}

// รับ input จาก user และเปลี่ยน \n เป็น \0 เพิ่อนำไปใช้ต่อ
void getInput(char *destination,int quota,FILE *stream){
     fgets(destination,quota,stdin);
     if (destination[strlen(destination) - 1] == '\n'){
        destination[strlen(destination) - 1] = '\0';
     }
                                        
}


/* 
ให่ token เก็บ string ที่ได้จาก strtok เพื่อรับ input 1 ตัวที่แยกโดย space และเข้า while loop จากนั้นเรียกใช้ฟังก์ชัน enQ เพื่อนำ token เข้าไปใน queue และวนลูปทำไปเรื่อยๆ จนกระทั่ง token เป็น NULL หรือนำ input ทั้งหมดเข้า queue แล้ว
โดยรับ parameter เป็น 
stream คือ string input ที่รับเข้ามาจาก user
queue คือ char array 2 มิติ สำหรับเก็บ input แต้ละตัวที่ต้องการใส้ใน queue เพิ่อสร้าง queue
max คือ จำนวนที่ผู่ใช้ต้องการนำข้อมูลมาใส่ใน queue (จำนวน input ที่มากที่สุดที่สามารถใส่เข้าไปใน queue ได้)
front คือ index ของข้อมูลตัวแรกสุดใน queue
rear คือ index ของข้อมูลตัวสุดท้ายใน queue
 */
void dataStreamHandler(char *stream,char (*queue)[STREAM_LENGHT], int *max,int *front,int *rear){
     char buffer[STREAM_LENGHT];
     int retVal = 0;
     strcpy(buffer,stream);
     char *token;
     token = strtok(buffer," ");
     while (token != NULL && retVal == 0){
           retVal = enQ(queue,token,max,front,rear);
           token = strtok(NULL," ");            
     }
}

/*
รับ parameter
numOfOut คือ จำนวนข้อมูลใน queue ที่ต้องการ dequeue ออกมา
for loop และเรียกใช้ function deQ เพื่อ dequeue  ข้อมูลออกมาจาก queue และใช้ output เป็น parameter เพื่่อเก็บข้อมูลที่ได้มาจาก queue จากนั้นปริ้นส์ output และวนลูปจนกระทั่ง dequeue ข้อมูลครบตาที่กำหนดไว้
*/
void output(char (*queue)[STREAM_LENGHT],int numOfOut,int *max,int *front,int *rear){
     int i = 0;
     int retval = 0;
     char output[STREAM_LENGHT];
     for (i = 0;i < numOfOut;i++){
         retval = deQ(queue,output,max,front,rear);
         printf("%s ",output);
     }
     printf("\n");
}



int enQ(char (*queue)[STREAM_LENGHT],char *data, int *max,int *front,int *rear){
    if (*front == 0 && *rear == (*max)-1){
       printf("FULLqueue\n");
       return -1;
    }
    if (*front == -1 && *rear == -1){
       *front = 0;
       *rear = 0;   
    }
    else if(*rear == (*max) -1 && *front != 0)
         *rear = 0;
    else {
         *rear = (*rear)+1;
         if (*rear == *front){
            *rear = (*rear)-1;
            printf("FULLqueue\n");
            return -1;         
         }
    } 
    strcpy(queue[*rear],data);
    return 0;
}

int deQ(char (*queue)[STREAM_LENGHT],char *destination,int *max,int *front,int *rear){
    if (*front == - 1){
       strcpy(destination,"None");
       return -1;
    }
    strcpy(destination,queue[*front]);
    if (*front == *rear){
       *front = -1;
       *rear = -1;
    }
    else {
         if (*front == (*max) - 1)
            *front = 0;
         else
             *front = (*front) + 1;
    }
    return 0;
}
