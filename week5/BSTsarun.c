#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct node { 
    int value;
    struct node *left;
    struct node *right;
    int balanceFactor;
    int height;
} node ;


node* createNewNode(int data) {
    node* newNode = calloc(1,sizeof(node));
    newNode->value = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->balanceFactor = 0;
    newNode->height = 1;
    return newNode;
}


void insertNode(node **rootPtr, node *newNode) {
    if (*rootPtr == NULL) {
        *rootPtr = newNode;
        return;
    }
    if (newNode->value < (*rootPtr)->value) {
        insertNode(&((*rootPtr)->left), newNode);
    } else {
        insertNode(&((*rootPtr)->right), newNode);
    }
}

// Preorder traversal
void preorderTraversal(struct node* root) {
  if (root == NULL) return;
  printf("%d ", root->value);
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}


void createTree(node** root){
    char text[109];
    fgets(text,100,stdin);

    int i = 0;
    while(text[i] != '\n') {
      i += 1;
    }
    text[i] = '\0';
  
    char* val = strtok(text, " ");
    while (val != NULL) 
    {
        insertNode(root, createNewNode(atoi(val)));
        val = strtok(NULL, " ");
    }
}


node* searchElement(node* root, int key, int *count){
    if(key == root->value){
        printf("found\n");
        printf("number of traverse %d\n", (*count));
        return root;
    }

    if (key < root->value) {
        (*count)++;
        searchElement(root->left, key, count);
    } else {
        (*count)++;
        searchElement(root->right, key, count);    
    }
}


int main(){
    node* root = NULL;
    int count = 0;
    createTree(&root);

    printf("Preorder Traversal:\n");
    preorderTraversal(root);
    printf("\nsearch result: ");
    searchElement(root, 12, &count);
}

