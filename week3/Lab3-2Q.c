#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack
{
    char *data; 
    struct stack *next;
} stack;

// get input for string
void stringInput(char *buffer)
{
    fgets(buffer, 100, stdin);
    if (buffer[strlen(buffer) - 1] == '\n')
    {
        buffer[strlen(buffer) - 1] = '\0';
    }
}

// make linked list stack from string
// without destroy string
stack *makeStack(char *buffer)
{
    stack *head = NULL;
    char *token = strtok(strdup(buffer), " ");
    while (token != NULL)
    {
        if (head != NULL)
        {
            stack *temp = malloc(sizeof(stack));
            temp->next = head;
            head = temp;
        }
        else
        {
            head = malloc(sizeof(stack));
            head->next = NULL;
        }
        head->data = malloc(sizeof(char) * strlen(token));
        strcpy(head->data, token);
        token = strtok(NULL, " ");
    }
    return head;
}

// pop forward stack
char *popForward(stack **head)
{
    if (*head == NULL)
    {
        return "None";
    }
    stack *temp = *head;
    (*head) = (*head)->next;
    char *buffer = strdup(temp->data);
    free(temp);
    return buffer;
}

// pop backward stack
char *popBackward(stack **head)
{   
    if (*head == NULL)
    {
        return "None";
    }
    stack *temp = *head;
    stack *prev = NULL;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    char *buffer = strdup(temp->data);
    free(temp);
    if (prev != NULL)
    {
        prev->next = NULL;
    }
    else
    {
        *head = NULL;
    }
    return buffer;
}

int main()
{
    char buffer[100];
    stringInput(buffer);
    stack *head1 = makeStack(buffer);
    stack *head2 = makeStack(buffer);

    while (head1 != NULL)
    {
        printf("%s ", popBackward(&head1));
    }
    printf("\n");
    while (head2 != NULL)
    {
        printf("%s ", popForward(&head2));
    }
}