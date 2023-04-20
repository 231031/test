#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void assignArray(int adjMatrix[], int num)
{
    for (int i = 0; i < num*num; i++)
    {
        adjMatrix[i] = 0;
    }
}

void removeEnter(char *str)
{
    if (str[strlen(str) - 1] == '\n')
        str[strlen(str) - 1] = '\0';
}


// find index of vertex for use in column adjMatrix
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
void createAdjMatrix(char *adj, int row, char vertex[], int adjMatrix[], int num)
{
    char *token;
    int column = -1, i = 0;
    token = strtok(adj, " "); // adj is adjacent vertex of this vertex
    while (token != NULL)
    {
        column = findAdj(token, vertex, num);
        if (column != -1)
        {
            adjMatrix[row + column] = 1; // array 1d row is num*row same as row in array 2d
        }
        token = strtok(NULL, " ");
    }
}

void displayAdjMatrix(int num, int adjMatrix[], char vertex[])
{
    int j = 0;
    int count = 0;
    for (int i = 0; i < num; i++)
    {
        count = 0;
        printf("%c ", vertex[i]);
        while (count < num) // display check each row from num that user input but will not loop index again because use array 1d
        {
            printf("%d ", adjMatrix[j]);
            j++;
            count++;
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
    int adjMatrix[num*num]; // size of array 1d is num*num     
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

        // check in case input of vertex not equal with number of vertex
        // delete num equal with number of input
        if (token == NULL && i < num)
            num--;
        else
        {
            vertex[i] = *token;
            token = strtok(NULL, " ");
        }

        i++;
    }

    // input adjacent vertex of each vertex
    i = 0;
    while (i < num)
    {
        printf("Enter adjacent vertex of vertex  %c : ", vertex[i]);
        fgets(input, 100, stdin);
        removeEnter(input);

        createAdjMatrix(input, num*i, vertex, adjMatrix, num);
        i++;
    }

    displayAdjMatrix(num, adjMatrix, vertex);

    return 0;
}