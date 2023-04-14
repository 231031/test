#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct treeNode
{
    int data;
    int balanceFactor;
    int height;
    struct treeNode *right;
    struct treeNode *left;
} TREENODE_T;

TREENODE_T *createdNode(int data)
{
    TREENODE_T *node = NULL;
    node = malloc(sizeof(TREENODE_T));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

void fillHeight(TREENODE_T *node)
{
    int height = 0;
    if (node->left != NULL)
    {
        fillHeight(node->left);
    }
    if (node->right != NULL)
    {
        fillHeight(node->right);
    }

    if (node->left == NULL && node->right == NULL)
        height = 1;
    else if (node->left == NULL)
        height = node->right->height + 1;
    else if (node->right == NULL)
        height = node->left->height + 1;
    else if (node->right->height > node->left->height)
        height = node->right->height + 1;
    else
        height = node->left->height + 1;

    node->height = height;
}

TREENODE_T* insertNode(TREENODE_T *root, TREENODE_T *newNode)
{
    int check = 0;
    if (root == NULL)
    {
        return newNode;
    }
    if (newNode->data > root->data)
        root->right = insertNode(root->right, newNode);
    else if (newNode->data < root->data)
        root->left = insertNode(root->left, newNode);

    return root;
}

TREENODE_T *searchElement(TREENODE_T *root, int key)
{
    int count = 0;
    TREENODE_T *pre = root;
    TREENODE_T *node = NULL;
    do 
    {
        if (pre->data == key)
            node = pre;
        else if (key > pre->data)
        {
            pre = pre->right;
            count++;
        }
        else // key < pre->data
        {
            pre = pre->left;
            count++;
        }     
    } while (pre != NULL && node == NULL);
    //printf("count search %d\n", count);
    return node;
}

int isDescendant(TREENODE_T *root, int keyI, int keyJ, TREENODE_T *nodeJ)
{
    // recursive function i เป็นลูกหลานของ j ไหม traverse ตั้งแต่ j แล้วหา i
    int check = 1;
    TREENODE_T *nodeI = searchElement(root, keyI);
    if (nodeJ == NULL)
        nodeJ = searchElement(root, keyJ);
    
    if (nodeI->data == nodeJ->data){
        printf("i descendants of j\n");
        return 0;
    }
    if (nodeJ->left != NULL && check != 0)
        check = isDescendant(root, keyI, keyJ, nodeJ->left);
    if (nodeJ->right != NULL && check != 0)
        check = isDescendant(root, keyI, keyJ, nodeJ->right);
}

int main()
{
    char str[100];
    char *token;
    int data;
    TREENODE_T *root = NULL;
    TREENODE_T *newNode = NULL;
    TREENODE_T *nodeJ = NULL;
    fgets(str, 100, stdin);
    str[strlen(str) - 1] = '\0';  

    token = strtok(str, " ");
    sscanf(token, "%d", &data);
    
    // loop for create and insert node in binary search tree
    while (token != NULL)
    {
        newNode = createdNode(data);
        root = insertNode(root, newNode);
        token = strtok(NULL, " ");
        sscanf(token, "%d", &data);
    }

    fillHeight(root);
    isDescendant(root, 21, 15, nodeJ);

}