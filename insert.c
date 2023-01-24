#include <stdio.h>
#define MAX 50
int main() {
    int number[MAX];
    char str[MAX];
    int pos = 0;
    int num = 0;
    int n = 0;
    int i = 0;

    printf("Enter number of elements : ");
    fgets(str, MAX, stdin);
    sscanf(str, "%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter number index %d : ", i);
        fgets(str, MAX, stdin);
        sscanf(str, "%d", &number[i]);
    }

    printf("Enter position that want to insert : ");
    fgets(str, MAX, stdin);
    sscanf(str, "%d", &pos);

    printf("Enter number that want to insert : ");
    fgets(str, MAX, stdin);
    sscanf(str, "%d", &num);

    i = n;
    while (i >= pos)
    {
        number[i] = number[i - 1];
        i--;
    }
    number[pos - 1] = num;
    n++;
    for (int i = 0; i < n; i++)
    {
        printf("%d ", number[i]);
    }
}
