#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char a[11000];

typedef struct node{
    char val[10];
    struct node* next;
}Node;

Node* createNode(char *val){
        Node *tmp= (Node*)malloc(sizeof(Node*));
        strcpy(tmp->val,val);
        printf("%s ",tmp->val);
        tmp->next=NULL;
        return tmp;

}

int isEmpty(Node* cur) {
    if (!cur) return 1;
    return 0;
}

Node* push(Node*cur,char* num) {
     struct node *tmp;
     tmp = createNode(num);
     if(!cur){
        cur = tmp;
        cur->next = NULL;
     }
     else{
        tmp->next = cur;
        cur = tmp;
     }
     return cur;
}

Node* pop(Node*cur) {
    struct node *tmp;
    if (isEmpty(cur)) {
        return;
    }
    else {
        tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    return cur;
}

void printAll(Node* cur){
    while(!isEmpty(cur))
    {
        printf("%s ",cur->val);
        cur = pop(cur);
    }
}

int main()
{
    Node*head=NULL;
    Node*cur=head;
    gets(a);
    char *token = strtok(a," ");
    while(token!=NULL){
        cur = push(cur,token);
        token = strtok(NULL," ");
    }
    printf("\n");
    printAll(cur);

    return 0;
}
/*
1 3 0 v 2

1a 12 13 s 15 16 17
*/