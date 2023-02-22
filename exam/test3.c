#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *data;
    int priority;
    struct node *next;
} Node;

typedef struct priority_queue {
    Node *head;
} PriorityQueue;

Node *createNode(char *data, int priority) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

PriorityQueue *createPriorityQueue() {
    PriorityQueue *newQueue = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    newQueue->head = NULL;
    return newQueue;
}

void enqueue(PriorityQueue *queue, char *data, int priority) {
    Node *newNode = createNode(data, priority);
    if (queue->head == NULL) {
        queue->head = newNode;
    } else if (priority > queue->head->priority) {
        newNode->next = queue->head;
        queue->head = newNode;
    } else {
        Node* currNode = queue->head;
        while (currNode->next != NULL && priority <= currNode->next->priority) {
            currNode = currNode->next;
        }
        newNode->next = currNode->next;
        currNode->next = newNode;
    }
}

char* dequeue(PriorityQueue *queue) {
    if (queue->head == NULL) {
        return "None";
    }
    char *data = queue->head->data;
    Node *tempNode = queue->head;
    queue->head = queue->head->next;
    free(tempNode);
    return data;
}

void printQueue(PriorityQueue *queue) {

    Node *currNode = queue->head;

    while (currNode != NULL) {
        printf("%s(%d) ", currNode->data, currNode->priority);
        currNode = currNode->next;
    }
    printf("\n");
}

int main()
{

}