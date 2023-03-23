#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct adjVertex
{
    void *pVertex;
    struct adjVertex *next;
} adjVertex;

typedef struct vertex
{
    char key[100];
    struct vertex *next;
    adjVertex *adjacentHead;
    adjVertex *adjacentTail;
} vertex;

void removeEnter(char *str)
{
    if (str[strlen(str) - 1] == '\n')
        str[strlen(str) - 1] = '\0';
}

void createAdj(vertex **presentVertex, char *key)
{
    // createNewAdjVertex
    adjVertex *newAdj = (adjVertex*) malloc(sizeof(adjVertex));
    newAdj->pVertex = (vertex*)*presentVertex; // link pVertex to vertex that this vertex is adjacent vertex
    newAdj->next = NULL;

    // link adjacentVertex
    if ((*presentVertex)->adjacentHead == NULL) 
    { 
        (*presentVertex)->adjacentHead  = newAdj;
        (*presentVertex)->adjacentTail  = newAdj;
    }
    else // link next of last adjacent vertex to newAdj and change last adjacent (adjacentTail) vertex to newAdj
    {
        (*presentVertex)->adjacentTail->next = newAdj;
        (*presentVertex)->adjacentTail = newAdj;
    }
}

void createVertex(vertex **vListHead, vertex **vListTail, char *key)
{
    // create new vertex
    vertex *newVertex = (vertex*)malloc(sizeof(vertex));
    strcpy(newVertex->key, key);
    newVertex->next = NULL;
    newVertex->adjacentHead = NULL;
    newVertex->adjacentTail = NULL;

    if (*vListHead == NULL)
    {
        *vListHead = newVertex;
        *vListTail = newVertex;
    }
    else // link last vertex to new vertex and change last vertex (vListTail) to newVertex
    {
        (*vListTail)->next = newVertex;
        (*vListTail) = newVertex;
    }
}

int main()
{
    char input[100];
    char *token;
    int num, i = 0;
    vertex *vListHead, *vListTail, *ptr;
    vListHead = NULL;
    vListTail = NULL;

    fgets(input, 100, stdin);
    sscanf(input, "%d", &num);

    fgets(input, 100, stdin);
    removeEnter(input);

    token = strtok(input, " ");
    while (i < num)
    {
        createVertex(&vListHead, &vListTail, token);
        token = strtok(NULL, " ");
        i++;
    }

    ptr = vListHead;
    // link adjacent vertex of each vertex
    while (ptr->next != NULL)
    {
        fgets(input, 100, stdin);
        token = strtok(input, " ");
        while (token != NULL)
        {
            createAdj(&ptr, token);
            token = strtok(NULL, " ");
        }
        ptr = ptr->next;
    }
    return 0;
}
