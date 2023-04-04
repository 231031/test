#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct tree {
  int data, balanceFactor, height;
  struct tree *left;
  struct tree *right;
} tree_T;

tree_T *createNewNode(int item) {
  tree_T *new_node = (tree_T *)calloc(1, sizeof(tree_T));
  new_node->data = item;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

tree_T *insertNode(tree_T *root, int item) {

  // tree_T *p = root, *previous = NULL;
  tree_T *insertedNode = createNewNode(item);
  if (root == NULL)
    return insertedNode;

  if (item < root->data) {
    root->left = insertNode(root->left, item); // keep node that come from return when function find NULL
  } else if (item > root->data) {
    root->right = insertNode(root->right, item);
  }

  // if left or right is added then return node for quit function
  return root;
}

void displayTree(tree_T *root) {
  if (root != NULL) {
    displayTree(root->left);
    printf("%d ", root->data);
    displayTree(root->right);
  }
}

tree_T* searchElement(tree_T* root, int key) {
  tree_T *p, *node;
  int count = 0;
  p = root; node = NULL;
  while((p != NULL) && (node == NULL)) {
      if (p->data == key){
        node = p; /*Search found*/
        printf("found\n");
      }
        
      else if (p->data > key)
      {
        p = p->left;
        count++;
      }
      else
      {
        p = p->right;
        count++;
      }
        
    } 

  printf("count %d", count);
  return (node);
}


int main(){
  tree_T *root1 = NULL;
  tree_T *root2 = NULL;
  tree_T *root3 = NULL;
  int item1[] = {30, 25, 12, 28, 40, 32, 41};
  int item2[] = {40, 32, 30, 25, 12, 28, 41};
  int item3[] = {41, 40, 32, 30, 28, 25, 12};
  int size = sizeof(item1) / sizeof(item1[0]);
  
  root1 = createNewNode(item1[0]);
  for (int i = 1; i < size; i++) {
    insertNode(root1, item1[i]);
  }

  root2 = createNewNode(item2[0]);
  for (int i = 1; i < size; i++) {
    insertNode(root2, item2[i]);
  }

  root3 = createNewNode(item3[0]);
  for (int i = 1; i < size; i++) {
    insertNode(root3, item3[i]);
  }
  
  printf("first pattern : ");
  displayTree(root1);
  printf("\n");

  printf("second pattern : ");
  displayTree(root2);
  printf("\n");
  
  printf("third pattern : ");
  displayTree(root3);
  printf("\n");
  
  searchElement(root1, 12);
  printf("\n");
  
  searchElement(root2, 12);
  printf("\n");
  
  searchElement(root3, 12);
  printf("\n");
  
  return 0;
}