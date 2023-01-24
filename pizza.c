#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
  char *name;
  int *price;
  int *total;
  int *add;
} STORE_T;

void back(char *str) {
  while (*str != '\0') {
    if (*str == '\n') {
      *str = '\0';
      break;
    }
    str++;
  }
}

int main() {
  int i = 0;
  char food[50];
  char check[50] = "END\n";
  char amount[10];
  char buffer[10];
  int count = 0;
  int totalPrice = 0;
  int input = 0;
  STORE_T *store = (STORE_T *)calloc(10, sizeof(STORE_T));
  for (int i = 0; i < 10; i++) {
    store[i].name = (char *)calloc(50, sizeof(char));
    store[i].price = (int *)calloc(3, sizeof(char));
    store[i].total = (int *)calloc(5, sizeof(int));
    store[i].add = (int *)calloc(5, sizeof(int));
    *(store[i]).add = 0;
  }

  while (1) {
    printf("Enter product name (or END) >");
    fgets(store[i].name, 50, stdin);
    if ((strcmp(store[i].name, check)) == 0) {
      break;
    }
    input++;
    printf("Enter price >");
    fgets(buffer, 5, stdin);
    sscanf(buffer, "%d", store[i].price);
    i++;
  }

  printf("Product List\n");
  for (int j = 0; j < i; j++) {
    back(store[j].name);
    printf("%d. %s %d Bath\n", j + 1, store[j].name, *(store[j]).price);
  }

  while (1) {
    printf("Enter product name (or END) >");
    fgets(food, 50, stdin);
    if (strcmp(food, check) == 0) {
      break;
    }

    printf("Qty >");
    fgets(amount, 5, stdin);
    sscanf(amount, "%d", &count);

    for (int j = 0; j < i; j++) {
      back(food);
      if (strcmp(food, store[j].name) == 0) {
        //printf("%d\n", count);
        *(store[j]).total += *(store[j]).price;
        *(store[j]).add += count;
      }
    }
  }

  printf("Receipt\n");
  for (int j = 0; j < input; j++) {

    if (*(store[j]).add != 0) {
      printf("%d. %s x %d = %d\n", j + 1, store[j].name, *(store[j]).add,
             ((*(store[j]).add) * (*(store[j]).price)));
      totalPrice += ((*(store[j]).add) * (*(store[j]).price));
    }
  }
  printf("Total Price = %d", totalPrice);
  return 0;
}