#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "apple,orange,banana";
    char *token = strtok(str, ",");
    printf("%s\n", token);
    printf("%s",str);
}