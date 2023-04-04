#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int countSearchBST = 0;
int countSearchAVL = 0;
typedef struct AVL_node
{
    int data;
    int height;
    int balanceFactor;
    struct AVL_node *left;
    struct AVL_node *right;

} AVL_NODE_T;

AVL_NODE_T *createNewNode(int data)
{
    AVL_NODE_T *new_node;
    new_node = (AVL_NODE_T *)malloc(sizeof(AVL_NODE_T));
    new_node->data = data;
    new_node->height = 0;
    new_node-> balanceFactor = 0;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

AVL_NODE_T *insertNode(AVL_NODE_T *root, int data)
{
    if (root == NULL)
    {
        root = createNewNode(data);
    }
    else if (data <= root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else
    {
        root->right = insertNode(root->right, data);
    }
    return root;
}

void fillHeight(AVL_NODE_T **start)
{
    AVL_NODE_T *ptr = *start;
    if (ptr == NULL)
    {
        return;
    }
    fillHeight(&ptr->left);
    fillHeight(&ptr->right);
    if (ptr->left == NULL && ptr->right == NULL)
    {
        ptr->height = 0;
    }
    else if (ptr->left == NULL)
    {
        ptr->height = ptr->right->height + 1;
    }
    else if (ptr->right == NULL)
    {
        ptr->height = ptr->left->height + 1;
    }
    else
    {
        if (ptr->left->height > ptr->right->height)
        {
            ptr->height = ptr->left->height + 1;
        }
        else
        {
            ptr->height = ptr->right->height + 1;
        }
    }
}

//balance factor
void fillBalanceFactor(AVL_NODE_T **start)
{
    AVL_NODE_T *ptr = *start;
    if (ptr == NULL)
    {
        return;
    }
    fillBalanceFactor(&ptr->left);
    fillBalanceFactor(&ptr->right);
    if (ptr->left == NULL && ptr->right == NULL)
    {
        ptr->balanceFactor = 0;
    }
    else if (ptr->left == NULL)
    {
        ptr->balanceFactor = -1 - ptr->right->height;
    }
    else if (ptr->right == NULL)
    {
        ptr->balanceFactor = ptr->left->height + 1;
    }
    else
    {
        ptr->balanceFactor = ptr->left->height - ptr->right->height;
    }
}

//cheack unbalanced node
void checkUnbalancedNode(AVL_NODE_T **start)
{
    AVL_NODE_T *ptr = *start;
    if (ptr == NULL)
    {
        return;
    }
    checkUnbalancedNode(&ptr->left);
    checkUnbalancedNode(&ptr->right);
    if (ptr->balanceFactor > 1 || ptr->balanceFactor < -1)
    {
        printf("\nUnbalanced node: %d", ptr->data);
    }
}



void displaytree(AVL_NODE_T *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("\nData :%d ", root->data);
    printf("\nHeight :%d ", root->height);
    printf("\nBalance Factor :%d ", root->balanceFactor);
    displaytree(root->left);
    displaytree(root->right);
}


//search element
AVL_NODE_T *searchBST (AVL_NODE_T *root,int data)
{
    AVL_NODE_T *temp = root;
    do
    {
        if (temp->data == data)
        {
            return temp;
        }
        else if (temp->data > data)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
        countSearchBST++;
    } while (root->data != data && root != NULL);
    
}

AVL_NODE_T *searchAVL (AVL_NODE_T *root,int data)
{
    AVL_NODE_T *temp = root;
    do
    {
        if (temp->data == data)
        {
            return temp;
        }
        else if (temp->data > data)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
        countSearchAVL++;
    } while (root->data != data && root != NULL);
    
}

AVL_NODE_T *rotateLeft(AVL_NODE_T *root)
{
    AVL_NODE_T *newRoot = root->right;
    root->right = newRoot->left;
    newRoot->left = root;
    return newRoot;
}

AVL_NODE_T *rotateRight(AVL_NODE_T *root)
{
    AVL_NODE_T *newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;
    return newRoot;
}

AVL_NODE_T *rotateLeftRight(AVL_NODE_T *root)
{
    root->left = rotateLeft(root->left);
    return rotateRight(root);
}

AVL_NODE_T *rotateRightLeft(AVL_NODE_T *root)
{
    root->right = rotateRight(root->right);
    return rotateLeft(root);
}


AVL_NODE_T *checkUnbalancedType(AVL_NODE_T *root)
{
    if (root->balanceFactor > 1) // left heavy
    {
        if (root->left->balanceFactor >= 0) // LL case
        {
            root = rotateRight(root);
        }
        else // LR case
        {
            root = rotateLeftRight(root);
        }
    }
    else if (root->balanceFactor < -1) // right heavy
    {
        if (root->right->balanceFactor <= 0) // RR case
        {
            root = rotateLeft(root);
        }
        else // RL case
        {
            root = rotateRightLeft(root);
        }
    }
    return root;
}




int main()
{
    AVL_NODE_T *root = NULL;
    char str[100];
    int data;

    fgets(str, 100, stdin);
    if(str[strlen(str)-1] == '\n')
    {
        str[strlen(str)-1] = '\0';
    }
    char *token = strtok(str, " ");
    while (token != NULL)
    {
        data = atoi(token);
        root = insertNode(root, data);
        token = strtok(NULL, " ");
    }
    fillHeight(&root);
    fillBalanceFactor(&root);
    printf("Preorder traversal:");
    displaytree(root);
    AVL_NODE_T *searchNode = searchBST(root, 12);
    printf("\nSearch = %d", searchNode->data);
    printf("\nSearch time = %d", countSearchBST);



    checkUnbalancedNode(&root);
    printf("\nAfter rotation: \n");
    AVL_NODE_T *newRoot = checkUnbalancedType(root);
    fillHeight(&newRoot);
    fillBalanceFactor(&newRoot);
    printf("Preorder traversal:");
    displaytree(newRoot);

    searchNode = searchAVL(newRoot, 12);
    printf("\nSearch = %d", searchNode->data);
    printf("\nSearch time = %d", countSearchAVL);


}
