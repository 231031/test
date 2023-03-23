#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct treeNode
{
    char data[100];
    int balanceFactor;
    int height;
    struct treeNode *right;
    struct treeNode *left;
} treeNode;

treeNode *createdNode(char *data)
{
    treeNode *node = NULL;
    node = malloc(sizeof(treeNode));
    strcpy(node->data, data);
    node->left = NULL;
    node->right = NULL;

    return node;
}

int setChild(treeNode **parent, treeNode *child, char direction)
{
    int success = 1;
    if (*parent == NULL || child == NULL)
    {
        printf("None\n");
        return 0;
    }
    if (direction == 'L')
    {
       (*parent)->left = child;
    }
    else if (direction == 'R')
    {
        (*parent)->right = child;
    }
    else
    {
        success = 0;
    }

    return success;
}

int getHeight(treeNode* node) {
    if (node == NULL) {
        return 0;
    }
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    return 1 + ((leftHeight > rightHeight) ? leftHeight : rightHeight);
}

void getBalanceFactor(treeNode** node) {
    int leftHeight = 0;
    int rightHeight = 0;

    if ((*node)->left != NULL) {
        leftHeight = getHeight((*node)->left);
    }
    if ((*node)->right != NULL) {
        rightHeight = getHeight((*node)->right);
    }

    (*node)->balanceFactor = leftHeight - rightHeight;
}

int postOrder(treeNode *root)
{
    treeNode *ptr = root;
    if (ptr->left != NULL) // ถ้าเข้าเงื่อนไขแล้วเข้าไปที่ function แล้วออกมาแล้วก็คือทำไปแล้ว เสร็จแล้วก็จะไปเช็ค right ค่อ
    {
        postOrder(ptr->left);
    }
    if (ptr->right != NULL)
    {
        postOrder(ptr->right);
    }
    printf("%s ", ptr->data);
    printf("%d\n", ptr->balanceFactor);
}


int main()
{
    int status = 0, check = 0;
    treeNode *root =  createdNode("General");

    treeNode *LG1 = createdNode("Lieutenant General1");
    treeNode *LG2 = createdNode("Lieutenant General2");

    treeNode *M1 = createdNode("Major General1");
    treeNode *M2 = createdNode("Major General2");
    treeNode *M3 = createdNode("Major General3");
    treeNode *M4 = createdNode("Major General4");
    treeNode *M5 = createdNode("Major General5");

    treeNode *C1 = createdNode("Colonel1");
    treeNode *C2 = createdNode("Colonel2");
    treeNode *C3 = createdNode("Colonel3");
    treeNode *C4 = createdNode("Colonel4");
    treeNode *C5 = createdNode("Colonel5");
    treeNode *C6 = createdNode("Colonel6");

    treeNode *LC1 = createdNode("Lieutenant Colonel1");
    treeNode *LC2 = createdNode("Lieutenant Colonel2");
    treeNode *LC3 = createdNode("Lieutenant Colonel3");
    treeNode *LC4 = createdNode("Lieutenant Colonel4");
    treeNode *LC5 = createdNode("Lieutenant Colonel5");
    treeNode *LC6 = createdNode("Lieutenant Colonel6");

    // setChild of root
    setChild(&root, LG1, 'L');

    // left of left sub tree
    // setChild of LG1 พลโท
    setChild(&LG1, M5, 'L');
    setChild(&LG1, LG2, 'R');

    // setChild of M5
    setChild(&M5, C6, 'L'); 
    setChild(&M5, M1, 'R'); 

    // setChild of C6
    setChild(&C6, LC1, 'L'); 
    setChild(&C6, C1, 'R');

    // setChild of C1 พันเอก
    setChild(&C1, LC2, 'L'); 

    // setChild of M1
    setChild(&M1, C2, 'L'); 
    setChild(&M1, M2, 'R');

    // setChild of C2
     setChild(&C2, LC3, 'L');

    // setChild of M2
    setChild(&M2, C3, 'L'); 

    // setChild of C3
    setChild(&C3, LC4, 'L');

    // setChild of M3 ตรี
    setChild(&M3, C4, 'L'); 

    // right of left sub tree
    // setChild of LG2 พลโท2
    setChild(&LG2, M3, 'L');

    // setChild of M3
    setChild(&M3, C4, 'L'); 
    setChild(&M3, M4, 'R');

    // setChild of C4
    setChild(&C4, LC5, 'L');

    // setChild of M4
    setChild(&M4, C5, 'L');

    // setChild of C5
    setChild(&C5, LC6, 'L');

    // fill height
    getBalanceFactor(&root);

    postOrder(root);
    return 0;
}