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
    node->height = 1;
    return node;
}


/*
recursive function
ลงไปจนถึง level แรกเพื่อเพิ่ม height ขึ้นเรื่อยๆ
*/
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

/*
recursive function
เพื่อหา node ที่เหมาะสมสำหรับนำ node ใหม่ไปใส่
*/
treeNode* insertNode(treeNode *root, treeNode *newNode)
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

// level order
int displayTreeLevel(treeNode *root)
{
    printf("%d ", root->data);
    if (root->left != NULL) // ถ้าเข้าเงื่อนไขแล้วเข้าไปที่ function แล้วออกมาแล้วก็คือทำไปแล้ว เสร็จแล้วก็จะไปเช็ค right ค่อ
    {
        displayTree(root->left);
    }
    if (root->right != NULL)
    {
        displayTree(root->right);
    }
}

int displayTreePre(treeNode *root) // root left right
{
    printf("%d ", root->data);
    if (root->left != NULL)
        displayTreePre(root->left);
    if (root->right != NULL)
        displayTreePre(root->right);
}


int displayTreeIn(treeNode *root) // left root right
{
    if (root != NULL)
    {
        displayTree(root->left);
        printf("%d ", root->data);
        displayTreeIn(root->right);
    }
}

int displayTreePost(treeNode *root) // left right root
{
    if (root->left != NULL) // ถ้าเข้าเงื่อนไขแล้วเข้าไปที่ function แล้วออกมาแล้วก็คือทำไปแล้ว เสร็จแล้วก็จะไปเช็ค right ค่อ
    {
        displayTree(root->left);
    }
    if (root->right != NULL)
    {
        displayTree(root->right);
    }
    printf("%d ", root->data);
}


// check searchElement
treeNode *searchElement(treeNode *root, int key)
{
    int count = 0;
    treeNode *pre = root;
    treeNode *node = NULL;
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
    printf("count search %d\n", count);
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
        root = insertNode(root, newNode);
        token = strtok(NULL, " ");
        sscanf(token, "%d", &data);
    }

    fillHeight(root);
    displayTree(root);
    printf("\n");
    searchElement(root, 12);

    
}