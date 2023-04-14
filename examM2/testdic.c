#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct treenode
{
    char word[100];
    struct treenode *left;
    struct treenode *right;
} TREENODE_T;

// List of functions with code
void removeEnter(char *str)
{
    if (str[strlen(str) - 1] == '\n')
        str[strlen(str) - 1] = '\0';
}

TREENODE_T *createdNode(char *token)
{
    TREENODE_T *node = NULL;
    node = malloc(sizeof(TREENODE_T));
    node->left = NULL;
    node->right = NULL;
    strcpy(node->word, token);
    return node;
}

TREENODE_T *insertNode(TREENODE_T *root, TREENODE_T *newNode)
{
    int check = 0, i = 0;
    if (root == NULL)
    {
        return newNode;
    }
    while (1) { // ถ้ามีการซ้ำกันของตัวอักษรเลื่อนไปเช็คตัวถัดไป
        if (newNode->word[i] > root->word[i]){
            root->right = insertNode(root->right, newNode);
            break;
        }
        else if (newNode->word[i] < root->word[i]){
            root->left = insertNode(root->left, newNode);
            break;
        } 
        i++;
    }
    return root;
}

int displayTreePost(TREENODE_T *root) // left right root
{
    if (root->left != NULL)
    {
        displayTreePost(root->left);
    }
    if (root->right != NULL)
    {
        displayTreePost(root->right);
    }
    printf("%s ", root->word);
}

int main()
{
    char input[10000];
    TREENODE_T *root = NULL, *newNode;

    fgets(input, 10000, stdin);
    removeEnter(input);
    char *token;

    token = strtok(input, " ");
    while (token != NULL)
    {
        newNode = createdNode(token);
        root = insertNode(root, newNode);
        token = strtok(NULL, " ");
    }

    displayTreePost(root);

    return 0;
}
