#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

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
void preorderTraversal(struct node *root) {
  if (root == NULL) return;
  printf("%d ", root->value);
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

//must call after fillBalanceFactor
node * toCriticalNode(node *ptr){
    while(abs(ptr->left->balanceFactor) > 1 || abs(ptr->right->balanceFactor) > 1 ){
        if(abs(ptr->left->balanceFactor) > 1 ){
            ptr = ptr->left;
        }
        else{
            ptr = ptr->right;
        }
    }
    return ptr;
}


void fillHeight(node* root){
    int height = 0;

    if (root->left!= NULL){
        fillHeight(root->left);
    }
    if (root->right!= NULL){
        fillHeight(root->right);
    }

    if (root->left == NULL && root->right == NULL){
        height = 0;
    }
    else if(root->left == NULL){
        height = root->right->height+1;
    }
    else if(root->right == NULL){
        height = root->left->height+1;
    }
    else if(root->right->height > root->left->height){
        height = root->right->height+1;
    }
    else{
        height = root->left->height+1;
    }

    root->height = height;
}


void fillBalanceFactor(node *root) {
    int leftHeight = 0,rightHeight = 0;

    if(root->left != NULL){
        fillBalanceFactor(root->left);
    }
    if(root->right != NULL){
        fillBalanceFactor(root->right);
    }

    if(root->left == NULL){
        leftHeight =-1;
    }
    else{
        leftHeight = root->left->height;
    }

    if(root->right == NULL){
        rightHeight =-1;
    }
    else{
        rightHeight = root->right->height;
    }

    root-> balanceFactor = leftHeight - rightHeight;

}

int checkUnbalanceType(node **root){
    int value = (*root)->value;
    node * ptr = *root;
    fillBalanceFactor(ptr);

    // Left Left Case 1
    if ((*root)->balanceFactor > 1 && value < (*root)->left->value)
        return 1;

    // Right Right Case 2
    if ((*root)->balanceFactor < -1 && value > (*root)->right->value)
        return 2;

    // Left Right Case 3
    if ((*root)->balanceFactor > 1 && value > (*root)->left->value) {
        (*root)->left = leftRotate((*root)->left);
        return 3;
    }

    // Right Left Case 4
    if ((*root)->balanceFactor < -1 && value < (*root)->right->value) {
        (*root)->right = rightRotate((*root)->right);
        return 4;
    }
    else
    {
        return 0;
    }
}

node* leftRotation(node **criticalNode){
    node* cptr = * criticalNode;
    
    node* rst = cptr->right;
    node* lower_lst = rst->left;

    rst->left = cptr;
    cptr->right = lower_lst;

    fillHeight(cptr);

    return rst;
}

node* rightRotation(node **criticalNode){
    node* cptr = * criticalNode;
    
    node* lst = cptr->left;
    node* lower_rst = lst->right;

    lst->right = cptr;
    cptr->left = lower_rst;

    fillHeight(cptr);

    return lst;
}

node* rotateLeftToRight(node **criticalNode){
    node* cptr = *criticalNode;
    node* lcptr = cptr->left;
    node* newRoot;

    leftRotation(&lcptr);
    newRoot = rightRotation(&cptr);

    return newRoot;
}

node* rotateRightToLeft(node **criticalNode){
    node* cptr = *criticalNode;
    node* rcptr = cptr->right;
    node* newRoot;

    rightRotation(&rcptr);
    newRoot = leftRotation(&cptr);

    return newRoot;
}

node* balanceAVL(node **root){
    fillHeight(*root);
    fillBalanceFactor(*root);

    node * ptr = toCriticalNode(*root);
    node * newRoot = *root;

    int type = checkUnbalanceType(root); 

    if(type == 1){
        newRoot = rightRotation(&ptr);
    }
    if(type == 2){
        newRoot = leftRotation(&ptr);
    }
    if(type == 3){
        newRoot = rotateLeftToRight(&ptr);
    }
    if(type == 4){
        newRoot = rotateRightToLeft(&ptr);
    }
    else{
        *root = newRoot;
        return newRoot;
    }
    *root = newRoot;
    return newRoot;
}

void createTreeAVL(node **root){
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
        balanceAVL(root);
        val = strtok(NULL, " ");
    }
}


node* searchElement(node* root, int key){
    if(key == root->value){
        printf("found");
        return root;
    }

    if (key < root->value) {
        searchElement(root->left, key);
    } else {
        searchElement(root->right, key);
    }
}







int main(){
    node* root = NULL;
    createTreeAVL(&root);

    preorderTraversal(root);
    searchElement(root, 12);
    return 0;
}




