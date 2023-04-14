typedef struct _adjVertex
{
    char key[100];
    void *pVertex;
    struct _adjVertex *next;
    EDGE_T *edge;
} ADJACENT_T;

typedef struct _vertex
{
    char key[100];
    struct _vertex *next;
    ADJACENT_T *adjacentHead;
    ADJACENT_T *adjacentTail;
}   VERTEX_T;

typedef struct _edge
{
    VERTEX_T *pFromVtx;
    VERTEX_T *pToVtx;
    int weight;
}   EDGE_T;