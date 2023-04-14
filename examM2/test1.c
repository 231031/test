#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _adjVertex
{
    char key[100];
    void *pVertex;
    struct _adjVertex *next;
} ADJACENT_T;

typedef struct _vertex
{
    char key[100];
    struct _vertex *next;
    ADJACENT_T *adjacentHead;
    ADJACENT_T *adjacentTail;
    char traverse[100];// keep key of vertex that traverse
    int *visited; // mark
}   VERTEX_T;

void removeEnter(char *str)
{
    if (str[strlen(str) - 1] == '\n')
        str[strlen(str) - 1] = '\0';
}

int main()
{

    return 0;
}