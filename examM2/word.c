#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct treeNode
{
    int data;
    int balanceFactor;
    int height;
    struct treeNode *right;
    struct treeNode *left;
} treeNode;

void addRoot(int bt[], int rootValue) { bt[0] = rootValue; }
void addRightChild(int bt[], int j, int value) { bt[2 * j + 1] = value; }
void addLeftChild(int bt[], int j, int value) { bt[2 * j + 2] = value; }

int countChildren(int bt[], int j)
{
    // assign every index in array = -1 before do everything
    int count = 0;
    if (bt[2 * j + 1] > -1)
        count++;
    if (bt[2 * j + 2] > -1)
        count++;
    return count;
}

int isOnlyChild(int bt[], int j)
{
    // assign every index in array = -1 before do everything
    int count = 0;
    if (bt[2 * j + 1] > -1)
        count++;
    if (bt[2 * j + 2] > -1)
        count++;

    if (count == 2)
    {
        //printf("Not only child\n");
        return 2;
    }
    else if (bt[2 * j + 1] > -1)
    {
        //printf("Only right child\n");
        return 1;
    }
    else if (bt[2 * j + 2] > -1)
    {
        //printf("Only left child\n");
        return 0;
    }
    else
    {
        //printf("Not have child\n");
        return -1;
    }
}

int countLeaves(int bt[], int arrSize)
{
    // assign every index in array = -1 before do everything
    int checkChild = 0, count = 0, j = 0;
    while (j < arrSize)
    {
        checkChild = 0;
        checkChild = isOnlyChild(bt, j);
        if (checkChild == -1)
        {
            printf("leaves\n");
            count++;
        }
        j++;
    }
    return count;
}

int main()
{
    int bt[10];
    for (int i = 0; i < 10; i++)
    {
        bt[i] = -1;
    }
    addRoot(bt, 12);
    addLeftChild(bt, 0, 10);
    addRightChild(bt, 0, 15);
    addLeftChild(bt, 2, 9);
    addRightChild(bt, 2, 11);
    printf("%d\n", countLeaves(bt, 10));
}