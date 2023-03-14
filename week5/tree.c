#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct treeNode
{
    char yos[100];
    int level;
    struct node *right;
    struct node *left;
} treeNode;

int setChildNode()
{
}

int postOrder()
{
}

int main()
{
    int level = 1;
    int countPre = 0;
    int countNew = 0;
    int check = 0;
    char input[1000];
    char count[100];
    char *token;
    while (input[0] != 'A')
    {
        fgets(input, 1000, stdin); // yos in same level
        fgets(count, 100, stdin);  // number of people in that level
        sscanf(count, "%d", &countPre);
        token = strtok(input, " ");
        if (level == 1 && check == 0)
        {
            struct treeNode *newNode = malloc(sizeof(treeNode));
            strcpy(newNode->yos, token);
            newNode->level = level;
            newNode->right = NULL;
            newNode->left = NULL;
            sscanf(count, "%d", &countPre);
            check++;
        }
        else
        {
            while (check < countNew)
            {
                struct treeNode *newNode = malloc(sizeof(treeNode));
                
                check++;
            }
        }
    }
}