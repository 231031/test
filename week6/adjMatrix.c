#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void assignArray(int adjMatrix[][10], int num)
{
    for(int i = 0; i < num; i++)
    {
        for(int j = 0; j < num; j++)
        {
            adjMatrix[i][j] = 0;
        }
    }   
}

void removeEnter(char *str)
{
    if (str[strlen(str) - 1] == '\n')
        str[strlen(str) - 1] = '\0';
}


int findAdj(char *token, char vertex[], int num)
{
    int i = 0;
    while (i < num)
    {
        if (*token == vertex[i])
        {
            return i;
        }
        i++;
    }

    return -1;
}

// create adjacency matrix of one vertex by using row of array to access
void createAdjMatrix(char *adj, int row, char vertex[], int adjMatrix[][10], int num)
{
    char *token;
    int column = -1, i = 0;
    token = strtok(adj, " "); // adj is all adjacency of this vertex
    while (token != NULL)
    {
        column = findAdj(token, vertex, num);
        if (column != -1)
        {
            adjMatrix[row][column] = 1;
        }
        token = strtok(NULL, " ");
    }
}

void displayAdjMatrix(int num, int adjMatrix[][10], char vertex[])
{
    for(int i = 0; i < num; i++)
    {
        printf("%c ", vertex[i]);
        for(int j = 0; j < num; j++)
        {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    char input[100];
    char *token;
    int num, i = 0;

    // input number of vertex
    printf("Enter number of vertex: ");
    fgets(input, 100, stdin);
    sscanf(input, "%d", &num);

    // create array for keep vertex and adjacency matrix
    char vertex[num];
    int adjMatrix[num][num];
    assignArray(adjMatrix, num);

    // input every vertex
    printf("Enter name of every vertex: ");
    fgets(input, 100, stdin);
    removeEnter(input);
    token = strtok(input, " ");
    while (i < num)
    {
        // check vertex that already have
        int check = 0, j = 0;
        if (i != 0)
        {
            while (j < i)
            {
                if (*token == vertex[j])
                {
                    check = -1;
                    break;
                }
                j++;
            }
        }
        if (check == -1) // if ซ้ำให้ข้ามลูปแล้วลด num ลง 1
        {
            num--;
            continue;
        }
        vertex[i] = *token;
        token = strtok(NULL, " ");

        // check in case input of vertex not equal with number of vertex
        if (token == NULL && i != num-1             )
            num--;

        i++;
    }

    // input adjacency of each vertex
    i = 0;
    while (i < num)
    {
        printf("Enter adjacency list of vertex  %c : ", vertex[i]);
        fgets(input, 100, stdin);
        removeEnter(input);

        createAdjMatrix(input, i, vertex, adjMatrix, num);
        i++;
    }
    
    displayAdjMatrix(num, adjMatrix, vertex);




    return 0;
}