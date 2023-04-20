#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct adjVertex
{
    char key[100];
    void *pVertex;
    struct adjVertex *next;
} adjVertex;

typedef struct vertex
{
    char key[100];
    struct vertex *next;
    adjVertex *adjacentHead;
    adjVertex *adjacentTail;
    char traverse[100];// keep key of vertex that traverse
    int *visited;
} vertex;

void removeEnter(char *str)
{
    if (str[strlen(str) - 1] == '\n')
        str[strlen(str) - 1] = '\0';
}


vertex* findVertexByKey(vertex *vListHead, char *key)
{
    vertex *findVertex = vListHead;
    
    while (findVertex != NULL && key[0] != '\0')
    {
        if (strcmp(key, findVertex->key) == 0) // if find vertex return
        {
            //printf("Find Vertex\n");
            return findVertex;
        }
        
        findVertex = findVertex->next;
    }    
    return NULL;

}

/*
vListHead สำหรับใช้เช็คว่ามี key ที่จะนำสร้าง adjacency vertex มีอยู่ใน vertex list ที่ใส่เข้ามาหรือป่าว ถ้ามีทำต่อ ถ้าไม่มีออกจาก function
*/
int createAdj(vertex *vListHead, vertex **presentVertex, char *key)
{
    // check that adjacent key have in vertex list? No return, Yes create and link 
    vertex *search = NULL;
    search = findVertexByKey(vListHead, key);
    if (search == NULL)
        return -1;


    // createNewAdjVertex
    adjVertex *newAdj = (adjVertex*) malloc(sizeof(adjVertex));
    newAdj->pVertex = (vertex*)*presentVertex; //pVertex in adjacency vertex link to vertex
    strcpy(newAdj->key, key);
    newAdj->next = NULL;

    // link adjacentVertex
    if ((*presentVertex)->adjacentHead == NULL) 
    { 
        (*presentVertex)->adjacentHead  = newAdj;
        (*presentVertex)->adjacentTail  = newAdj;
    }
    else // link next of adjacentTail to newAdj then change adjacentTail vertex to newAdj (adjacentTail is last adjacent in list)
    {
        (*presentVertex)->adjacentTail->next = newAdj;
        (*presentVertex)->adjacentTail = newAdj;
    }
}

// create vertex list
int createVertex(vertex **vListHead, vertex **vListTail, char *key)
{
    // จะสร้าง vertex เมื่อยังไม่มี vertex นั้น (key ต้องไม่ซ้ำกับ vertex เดิมที่มีอยู่แล้ว)
    vertex *search = NULL;
    search = findVertexByKey(*vListHead, key);
    if (search != NULL)
        return -1;

    // create new vertex
    vertex *newVertex = (vertex*)malloc(sizeof(vertex));
    strcpy(newVertex->key, key);
    newVertex->next = NULL;
    newVertex->adjacentHead = NULL;
    newVertex->adjacentTail = NULL;

    if (*vListHead == NULL) // head of vertex list
    {
        *vListHead = newVertex;
        *vListTail = newVertex;
    }
    else // link last vertex to new vertex than change last vertex (vListTail) to newVertex
    {
        (*vListTail)->next = newVertex;
        (*vListTail) = newVertex;
    }
}


int displayAdj(adjVertex *headAdj) // head of adjacent list of present vertex
{
    if (headAdj == NULL) // check in case this vertex not have adjacency list
        return -1;
    printf("%s ", headAdj->key);

    // recursive function for display Adjacency list of this vertex
    if (headAdj->next != NULL)
        displayAdj(headAdj->next);
}

int displayGraph(vertex *vListHead)
{
    vertex *displayVertex = vListHead;
    if (displayVertex == NULL)
        return -1;
    printf("Vertex %s : ", displayVertex->key);
    displayAdj(displayVertex->adjacentHead); // call function and send adjacentHead to display adjacent list of this vertex
    printf("\n");

    // recursive function for display every vertex
    if (displayVertex->next != NULL)
        displayGraph(displayVertex->next);
}

// void freeAdjacentList(vertex *curVertex)
// {
//     adjVertex *curAdj = curVertex->adjacentHead;
//     adjVertex *delAdj = NULL;
//     while (curAdj != NULL)
//     {
//         delAdj = curAdj;
//         curAdj = curAdj->next;
//         free(delAdj);
//     }
//     curVertex->adjacentHead = NULL;
//     curVertex->adjacentTail = NULL;
// }

// void clearGraph(vertex *vListHead)
// {
//     vertex *curVertex = vListHead;
//     vertex *delVertex = NULL;
//     while (curVertex != NULL)
//     {
//         freeAdjacentList(curVertex);
//         delVertex = curVertex;
//         curVertex = curVertex->next;
//         free(delVertex->key);
//         free(delVertex);
//     }
// }


int main()
{
    char input[100];
    char *token;
    int num, i = 0;
    vertex *vListHead, *vListTail, *ptr;
    vListHead = NULL; // Head of vertex list
    vListTail = NULL;

    // input number of vertex
    printf("Enter number of vertex: ");
    fgets(input, 100, stdin);
    sscanf(input, "%d", &num);

    // input every vertex
    printf("Enter name of every vertex: ");
    fgets(input, 100, stdin);
    removeEnter(input);

    // create vertex list
    token = strtok(input, " ");
    while (token != NULL && i < num)
    {
        createVertex(&vListHead, &vListTail, token);
        token = strtok(NULL, " ");
        i++;
    }


    ptr = vListHead;
    // create adjacent list of each vertex
    // loop ใหญา 1 ครั้ง คือสร้าง adjacent list ให้ 1 vertex
    // loop เล็ก สร้างและ link adjacent 1 อัน ใน adjacent list ที่รับมา ของ 1 vertex
    while (ptr != NULL) 
    {
        // input adjacency list of each vertex
        printf("Enter adjacency list of vertex %s : ", ptr->key);
        fgets(input, 100, stdin);
        removeEnter(input);

        token = strtok(input, " ");
        // loop to create and link 1 adjacent in adjacent list until finish 
        while (token != NULL)
        {
            // ส่ง vListHead เพื่อเช็คว่า adjacent ที่รับ input เข้ามามีอยู่ใน vertex ไหม
            createAdj(vListHead, &ptr, token);
            token = strtok(NULL, " ");
        }
        ptr = ptr->next; // ไปที่ vertex ถัดไปเพื่อสร้าง adjacent list ให้ vertex นั้นต่อ
    }

    // Adjacency List
    displayGraph(vListHead);
    return 0;
}
