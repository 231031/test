#include <stdio.h>
#include <stdlib.h>
typedef struct {
    char *name;
    char *subject;
    char *grade;
} STUDENT_T;

int main()
{
    
    char buffer[50];
    int count = 0;

    fgets(buffer, 50, stdin);
    sscanf(buffer, "%d", &count);
    printf("%d\n", count);
    STUDENT_T *student = (STUDENT_T*) malloc(count*sizeof(STUDENT_T));
    for (int i = 0; i < count; i++)
    {
        student[i].name = (char*) malloc(50*sizeof(char));
        student[i].subject = (char*) malloc(50*sizeof(char));
        student[i].grade = (char*) malloc(10*sizeof(char));
    }
    for (int i = 0; i < count; i++)
    {
        printf("Enter name : ");
        fgets(student[i].name, 50, stdin);

        printf("Enter subject : ");
        fgets(student[i].subject, 50, stdin);

        printf("Enter grade : ");
        fgets(student[i].grade, 50, stdin);
    }


    for (int i = 0; i < count; i++)
    {
        printf("name student #%d : %s", i+1, student[i].name);
        printf("subject student #%d : %s", i+1, student[i].subject);
        printf("grade student #%d : %s\n", i+1, student[i].grade);

    }



    return 0;
}