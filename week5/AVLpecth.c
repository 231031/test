#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node {
    int data;
    struct Node *left, *right;
    int height;
} Node;

Node* createNode(int num){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = num;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

void enterKiller(char *str){
    if(str[strlen(str)-1] == '\n'){
        str[strlen(str)-1] = '\0';
    }
}
int maxOf(int a,int b){
    if(a>b)
        return a;
    else
        return b;
}

int heightOf(Node *node){
    if(node == NULL)
        return 0;
    else
        return node->height;
}

int getBalance(Node *node){
    if(node == NULL)
        return 0;
    else
        return heightOf(node->left) - heightOf(node->right);
}

int checkUnbalance(Node *node,int num){

    int balanceFactor = getBalance(node);

    if(balanceFactor > 1 && num < node->left->data)
        return 1;

    if(balanceFactor < -1 && num > node->right->data)
        return 2;

    if(balanceFactor > 1 && num > node->left->data)
        return 3;

    if(balanceFactor < -1 && num < node->right->data)
        return 4;

    return -1;

}
Node* leftRotate(Node* node){

    Node *x = node;
    Node *y = node->right;
    Node *z = y->left;

    y->left=x;
    x->right=z;

    x->height = maxOf(heightOf(x->left),heightOf(x->right))+1;
    y->height = maxOf(heightOf(y->left),heightOf(y->right))+1;

    return(y);

}

Node* rightRotate(Node*node){

    Node *x = node;
    Node *y = node->left;
    Node *z = y->right;

    y->right=x;
    x->left=z;

    x->height = maxOf(heightOf(x->left),heightOf(x->right))+1;
    y->height = maxOf(heightOf(y->left),heightOf(y->right))+1;

    return(y);
}

Node* leftrightRotate(Node*node){

    node->left =  leftRotate(node->left);
    return rightRotate(node);
}

Node* rightleftRotate(Node*node){

    node->right = rightRotate(node->right);
    return leftRotate(node);
}

Node* insertNode(Node* node,int num){

    if(node == NULL){
        Node *newNode = createNode(num);
        return newNode;
    }

    if(num < node->data)
        node->left = insertNode(node->left,num);
    else if(num > node->data)
        node->right = insertNode(node->right,num);
    else
        return node;

    node->height = 1 + maxOf(heightOf(node->left),heightOf(node->right));

    int unBalancetype = checkUnbalance(node,num);

    if(unBalancetype == 1)
        return rightRotate(node);

    if (unBalancetype == 2)
        return leftRotate(node);

    if (unBalancetype == 3)
    {
        return leftrightRotate(node);
    }

    if (unBalancetype == 4)
    {
        return rightleftRotate(node);
    }

    return node;
}

void displayNode(Node* node){
    printf("%d height : %d",node->data,node->height);
    if(node->left != NULL)
        printf(" left : %d",node->left->data);
    if(node->right != NULL)
        printf(" right : %d",node->right->data);
    printf("\n");
}

void displayTree(Node* root){
    if(root == NULL)
        return;
    displayNode(root);
    displayTree(root->left);
    displayTree(root->right);
}
void inTraverse(Node* root){
    if(root == NULL)
        return;
    inTraverse(root->left);
    printf("%d ",root->data);
    inTraverse(root->right);
}
void postTraverse(Node* root){
    if(root == NULL)
        return;
    postTraverse(root->left);
    postTraverse(root->right);
    printf("%d ",root->data);
}

Node* searchBST(Node* node,int num){
    if (node == NULL || num == node->data) {
        return node;
    }
    Node* leftNode = searchBST(node->left, num);
    Node* rightNode = searchBST(node->right, num);
    if (leftNode != NULL) {
        return leftNode;
    } else {
        return rightNode;
    }

}
int main(){
    Node *root = NULL;
    char input[7887];
    fgets(input,7057,stdin);
    enterKiller(input);
    char *ptr = strtok(input,", ");
    int num = atoi(ptr);
    while(ptr != NULL){
        num = atoi(ptr);
        //printf("%d\n",num);
        root = insertNode(root,num);
        ptr = strtok(NULL,", ");
    }

    displayTree(root);

    printf("Search for: ");
    fgets(input,5050,stdin);
    enterKiller(input);
    num = atoi(input);
    Node *Founded = searchBST(root,num);
    if(Founded != NULL){
        printf("Found it !!!\n");
        inTraverse(Founded);
    }
    else
        printf("Sorry Not Found T-T");
    return 0;
}
// 30, 25, 12, 28, 40, 32, 41
// 40, 32, 30, 25, 12, 28, 41
// 41, 40, 32, 30, 28, 25, 12
