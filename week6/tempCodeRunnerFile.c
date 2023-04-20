    // input adjacency of each vertex
    i = 0;
    while (i < num)
    {
        printf("Enter adjacency list of vertex  %c : ", vertex[i]);
        fgets(input, 100, stdin);
        removeEnter(input);

        createAdjMatrix(input, num*i, vertex, adjMatrix, num);
        i++;
    }

    displayAdjMatrix(num, adjMatrix, vertex);

    return 0;
}