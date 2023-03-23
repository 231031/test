#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct treeNode
{
    int data;
    int balanceFactor;
    int height;
    int balanceType;
    struct treeNode *right;
    struct treeNode *left;
} treeNode;

treeNode *createdNode(int data) // 0 is balance
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


void fillHeight(treeNode *node)
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
        height = 0;
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

void fillBalanceFactor(treeNode *node)
{
    int leftHeight = 0, rightHeight = 0;
    if (node->left != NULL)
        fillBalanceFactor(node->left);
    if (node->right != NULL)
        fillBalanceFactor(node->right);
    
    if (node->left == NULL)
        leftHeight = 0;
    else
        leftHeight = node->left->height + 1;

    if (node->right == NULL)
        rightHeight = 0;
    else
        rightHeight = node->right->height + 1;

    node->balanceFactor = leftHeight - rightHeight;
}

int checkUnbalanceType(treeNode *node)
{
    int check = 0;

}

// rotate function

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

    fillHeight(root);
    fillBalanceFactor(root);
}