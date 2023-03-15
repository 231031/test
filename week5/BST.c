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
} treeNode;

treeNode *createdNode(int data)
{
    treeNode *node = NULL;
    node = malloc(sizeof(treeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

int insertNode(treeNode **root, treeNode *newNode)
{
    int check = 0;
    treeNode *p, *previous;
    if (*root == NULL)
    {
        *root = newNode;
    }
    else
    {
        p = *root;
        previous = *root;
        if (p->left == NULL && p->right == NULL)
        {
            if (newNode->data > p->data)
            {
                p->right = newNode;
            }
            else if (newNode->data < p->data)
            {
                p->left = newNode;
            }
            return 0;
        }
        
        while (p->left != NULL || p->right != NULL)
        {
            if (newNode->data > p->data)
            {
                if (p->right == NULL)
                {
                    p->right = newNode;
                    check = 0;
                    return 0;
                }
                previous = p;
                p = p->right;
            }
            else if (newNode->data < p->data)
            {
                if (p->left == NULL)
                {
                    p->left == newNode;
                    check = 0;
                    return 0;
                }
                previous = p;
                p = p->left;
            } 
        } 

        // when find node that both left and right is NULL so check that what side have to add
        if (newNode->data > p->data)
        {
            p->right = newNode;
        }
        else if (newNode->data < p->data)
        {
            p->left = newNode;
        }
        return 0;

    }
}
/*
int displayTree(treeNode *root)
{
    treeNode *ptr = root;
    if (ptr->left != NULL) // ถ้าเข้าเงื่อนไขแล้วเข้าไปที่ function แล้วออกมาแล้วก็คือทำไปแล้ว เสร็จแล้วก็จะไปเช็ค right ค่อ
    {
        printf("%d ", ptr->data);
        displayTree(ptr->left);
    }
    if (ptr->right != NULL)
    {
        printf("%d ", ptr->data);
        displayTree(ptr->right);
    }
}
*/

// postOrder
int displayTree(treeNode *root)
{
    treeNode *ptr = root;
    if (ptr->left != NULL) // ถ้าเข้าเงื่อนไขแล้วเข้าไปที่ function แล้วออกมาแล้วก็คือทำไปแล้ว เสร็จแล้วก็จะไปเช็ค right ค่อ
    {
        displayTree(ptr->left);
    }
    if (ptr->right != NULL)
    {
        displayTree(ptr->right);
    }
    printf("%d ", ptr->data);
}

// check searchElement
treeNode *searchElement(treeNode *root, int key)
{
    treeNode *pre = root;
    treeNode *node = NULL;
    do 
    {
        if (pre->data == key)
            node = pre;
        else if (key > pre->data)
            pre = pre->right;
        else // key < pre->data
            pre = pre->left;
    } while (pre != NULL && node == NULL);

    return node;
}



int main()
{
    char str[100];
    char *token;
    int data;
    treeNode *root = NULL;
    treeNode *newNode = NULL;
    fgets(str, 100, stdin);
    str[strlen(str) - 1] = '\0';  

    token = strtok(str, " ");
    sscanf(token, "%d", &data);
    
    while (token != NULL)
    {
        newNode = createdNode(data);
        insertNode(&root, newNode);
        token = strtok(NULL, " ");
        sscanf(token, "%d", &data);
    }

    displayTree(root);
}