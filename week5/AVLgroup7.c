#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int searchRound;

typedef struct node {
    int key;
    struct node *left;
    struct node *right;
    int height;
    int balanceFactor;
}node;

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

void balanceFactor(node* root) {
    int leftHeight = 0,rightHeight = 0;

    if(root->left != NULL){
        balanceFactor(root->left);
    }
    if(root->right != NULL){
        balanceFactor(root->right);
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

node* createNewNode(int key) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 0;
    node->balanceFactor = 0;
    return (node);
}

node *rightRotate(node *y) {
    struct node *x = y->left;
    struct node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    fillHeight(x);

    // Return new root
    return x;
}

node *leftRotate(node *x) {
    struct node *y = x->right;
    struct node *T2 = y->left;

    y->left = x;
    x->right = T2;

    fillHeight(y);

    // Return newRoot
    return y;
}

node *leftrightRotate(node *criticalNode) {
    criticalNode->left = leftRotate(criticalNode->left);
    return rightRotate(criticalNode);
}

node *rightleftRotate(node *criticalNode) {
    criticalNode->right = rightRotate(criticalNode->right);
    return leftRotate(criticalNode);
}

int checkUnbalanceType(node* criticalNode, int newNodeValue){
    int balance;
    balance = criticalNode->balanceFactor;

    if (balance > 1 && newNodeValue < criticalNode->left->key){ //leftofleft
        return 1; //case 1
    }


    if (balance < -1 && newNodeValue > criticalNode->right->key){ //rightofright
        return 2; //case 2
    }


    if (balance > 1 && newNodeValue > criticalNode->left->key) {//rightofleft
        return 3; //case 3
    }


    if (balance < -1 && newNodeValue < criticalNode->right->key) {//leftofright
        return 4; //case 4
    }

    return 0; //already balance
}

node* insert(node* node, int key) {
    /* 1.  Perform the normal BST rotation */
    if (node == NULL)
        return (createNewNode(key));

    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    fillHeight(node);
    balanceFactor(node);
    

    int Case = checkUnbalanceType(node, key);

    // Left Left Case
    if (Case == 1){
        return rightRotate(node);
    }

    // Right Right Case
    if (Case == 2){
        return leftRotate(node);
    }

    // Left Right Case
    if (Case == 3) {
        return leftrightRotate(node);
    }

    // Right Left Case
    if (Case == 4) {
        return rightleftRotate(node);
    }

    return node;
}

void inorderTraversal(node* root) {
  if (root != NULL) {
  inorderTraversal(root->left);
  printf("%d ->", root->key);
  inorderTraversal(root->right);
  }
}

void preorderTraversal(node* root) {
  if (root == NULL) return;
  printf("%d ->", root->key);
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

node* searchElement(node* root, int key){
    if(root == NULL){
        printf("not found\n");
        printf("Recursion iterations : %d", searchRound);
        return ;
    }

    if(key == root->key){
        printf("found\n");
        printf("Recursion iterations  : %d", searchRound);
        return root;
    }

    if (key < root->key) {
        searchRound++;
        searchElement(root->left, key);
    } else {
        searchRound++;
        searchElement(root->right, key);
    }
}

int main() {
    searchRound = 0;
    node *root = NULL;

    root = insert(root, 30);
    root = insert(root, 25);
    root = insert(root, 12);
    root = insert(root, 28);
    root = insert(root, 40);
    root = insert(root, 32);
    root = insert(root, 41);
    

    printf("In order traversal of the constructed Balanced Binary tree is \n");
    inorderTraversal(root);
    printf("\nsearch for : 40\n");
    searchElement(root, 40);
}