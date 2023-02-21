#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data[101];
    int priority;
    struct Node* next;
};

struct Node* createNode(char data[], int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode != NULL) {
        for (int i = 0; data[i] != '\0'; i++) {
            newNode->data[i] = data[i];
        }
        newNode->priority = priority;
        newNode->next = NULL;
    }
    return newNode;
}

struct Node* enqueue(struct Node* head, char data[], int priority) {
    struct Node* newNode = createNode(data, priority);
    if (newNode != NULL) {
        if (head == NULL || priority < head->priority) {
            newNode->next = head;
            head = newNode;
        } else {
            struct Node* current = head;
            while (current->next != NULL && current->next->priority <= priority) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }
    return head;
}

struct Node* dequeue(struct Node* head, char data[]) {
    if (head != NULL) {
        struct Node* temp = head;
        for (int i = 0; head->data[i] != '\0'; i++) {
            data[i] = head->data[i];
        }
        data[100] = '\0';
        head = head->next;
        free(temp);
    } else {
        data[0] = 'N';
        data[1] = 'o';
        data[2] = 'n';
        data[3] = 'e';
        data[4] = '\0';
    }
    return head;
}

int main() {
    struct Node* head = NULL;
    char input[201];
    int priority, n;
    scanf("%[^\n]%*c", input);
    char* token = strtok(input, " ");
    while (token != NULL) {
        priority = atoi(&token[strlen(token) - 1]);
        token[strlen(token) - 2] = '\0';
        head = enqueue(head, token, (priority >= 0 && priority <= 9) ? priority : -1);
        token = strtok(NULL, " ");
    }
    scanf("%d", &n);
    char data[101];
    for (int i = 0; i < n; i++) {
        head = dequeue(head, data);
        printf("%s\n", data);
    }
    return 0;
}