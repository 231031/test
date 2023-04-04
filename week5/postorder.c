#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
เริ่มต้นประกาศ struct treeNode ที่จะใช้เป็นที่เก็บข้อมูลของ node แต่ละ node ใน binary tree
*/
typedef struct treeNode
{
    char data[100];
    int balanceFactor;
    int height;
    struct treeNode *right;
    struct treeNode *left;
} treeNode;

/*
Function createNode
จากนั้นสร้าง function createNode 
เพื่อใช้สำหรับสร้าง node และใส่ข้อมูลให้แต่ละ node ใน binary tree
*/
treeNode *createdNode(char *data)
{
    treeNode *node = NULL;
    node = malloc(sizeof(treeNode));
    strcpy(node->data, data);
    // ให้ทั้ง left และ right ของแต่ละ node ที่ถูกสร้างเป็น NULL ก่อน
    node->left = NULL;
    node->right = NULL;

    return node;
}

/*
Function setChild
ใช้สำหรับ set child ให้แต่ละ node ใน binary tree โดยรับพารามิเตอร์เป็น 
-	Parent node ที่ต้องการจะ set child
-	Child node ที่ต้องการจะเพิ่มเข้ามาใน binary tree
-	ทิศทางที่ต้องการให้ child node อยู่
*/
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

/*
Function fillHeight
ใช้สำหรับหา height ให้กับแต่ละ node ใน binary tree โดยรับพารามิเตอร์เป็น root ของ binary tree 
และใช้เรื่อง recursive function ในการคำนวณหา height ให้กับแต่ละ node
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
Function fillBalanceFactor
ใช้สำหรับหา balance factor ของ แต่ละ node ใน binary tree
โดยนำ left height ของ node ที่ต้องหา balance factor ลบกับ right height ของ node เดียวกัน
*/
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
        leftHeight = node->left->height;

    if (node->right == NULL)
        rightHeight = 0;
    else
        rightHeight = node->right->height;

    node->balanceFactor = leftHeight - rightHeight;
}

/*
Function postOrder
ใช้สำหรับ traverse binary tree แบบ post order left-right-root
โดยใช้จะนำ recursive function มาใช้
*/
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

/*
void printLevel(Node* node, int level) {
    if (node == NULL) {
        return;
    }
    if (level == 1) {
        printf("%d ", node->data);
    }
    else if (level > 1) {
        printLevel(node->left, level - 1);
        printLevel(node->right, level - 1);
    }
}

// perform level order traversal of the binary search tree
void levelOrderTraversal(Node* node) {
    int height = getHeight(node);
    for (int i = 1; i <= height; i++) {
        printLevel(node, i);
    }
}
*/

int main()
{
    int status = 0, check = 0;

    // สร้าง node แต่ละ node และใส่ข้อมูลที่ต้องการเก็บใน node ใน parameter 

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

    // set child ให้แต่ละ node โดยเริ่มตั้งแต่ root
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
    fillHeight(root);
    fillBalanceFactor(root);

    postOrder(root);
    return 0;
}