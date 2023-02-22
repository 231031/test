#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char data;
    int priority;
    struct node *next;
} Node;

typedef struct priority_queue
{
    Node *head;
} PriorityQueue;

Node *createNode(char data, int priority)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

PriorityQueue *createPriorityQueue()
{
    PriorityQueue *newQueue = (PriorityQueue *)malloc(sizeof(PriorityQueue));
    newQueue->head = NULL;
    return newQueue;
}

void enqueue(PriorityQueue *queue, char data, int priority)
{
    Node *newNode = createNode(data, priority);
    if (queue->head == NULL)
    {
        queue->head = newNode;
    }
    else if (priority > queue->head->priority)
    {
        newNode->next = queue->head;
        queue->head = newNode;
    }
    else
    {
        Node *currNode = queue->head;
        while (currNode->next != NULL && priority <= currNode->next->priority)
        {
            currNode = currNode->next;
        }
        newNode->next = currNode->next;
        currNode->next = newNode;
    }
}

char dequeue(PriorityQueue *queue)
{
    if (queue->head == NULL)
    {
        return 'N';
    }
    char data = queue->head->data;
    Node *tempNode = queue->head;
    queue->head = queue->head->next;
    free(tempNode);
    return data;
}

void printQueue(PriorityQueue *queue)
{

    Node *currNode = queue->head;

    while (currNode != NULL)
    {
        printf("%s(%d) ", currNode->data, currNode->priority);
        currNode = currNode->next;
    }
    printf("\n");
}

void deleteEnter(char *str)
{
    if (str[strlen(str) - 1] == '\n')
    {
        str[strlen(str) - 1] = '\0';
    }
}

int priorityInput(char chr)
{
    int priority = 0;
    if (chr == 'a' || chr == 'A' || chr == 'e' || chr == 'E' || chr == 'i' || chr == 'I' || chr == 'o' || chr == 'O' || chr == 'U' || chr == 'u' || chr == '.' || chr == '!')
    {
        priority = 1;
    }
    else
    {
        priority = 0;
    }
    return priority;
}

int main()
{
    PriorityQueue *queue = createPriorityQueue();
    char str[1000];
    char str2[1000];
    int priority = 0;
    int i = 0;
    int j = 0;

    fgets(str, 1000, stdin);
    deleteEnter(str);
    char *ptr = strtok(str, " ");
    while (ptr != NULL)
    {
        i = 0;
        char *strPtr = ptr;
        while (i < strlen(strPtr))
        {
            str2[j] = strPtr[i];
            j++;
            i++;
        }
        ptr = strtok(NULL, " ");
    }

    i = 0;
    while (i < j)
    {
        priority = priorityInput(str2[i]);
        enqueue(queue, str2[i], priority);
        i++;
    }
    //printQueue(queue);

    
    for (int i = 0; i < j; i++)
    {
        char c = dequeue(queue);
        printf("%c", c);
    }
    return 0;
}