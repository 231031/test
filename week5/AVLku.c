#include<stdio.h>
#include<stdlib.h>

// An AVL tree node
struct node {
    int key;
    struct node *left;
    struct node *right;
    int height;
};

// A utility function to get maximum of two integers
int max(int a, int b);

// A utility function to get height of the tree
int height(struct node *N) {
    if (N == NULL)
        return 0;
    return N->height;
}

// A utility function to get maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

/* Helper function that allocates a new node with the given key and
 NULL left and right pointers. */
struct node* newNode(int key) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // new node is initially added at leaf
    return (node);
}

// A utility function to right rotate subtree rooted with y
// See the diagram given above.
struct node *rightRotate(struct node *y) {
    struct node *x = y->left;
    struct node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
struct node *leftRotate(struct node *x) {
    struct node *y = x->right;
    struct node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    //  Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}


// Get Balance factor of node N
int getBalance(struct node *N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// check that type of unbalancedType and check rotate
int checkUnbalancedType(struct node* node, int num)
{
    int balance;
    balance = getBalance(node);

    // Left Left Case 1
    if (balance > 1 && num < node->left->key)
        return 1;

    // Right Right Case 2
    if (balance < -1 && num > node->right->key)
        return 2;

    // Left Right Case 3
    if (balance > 1 && num > node->left->key) {
        return 3;
    }

    // Right Left Case 4
    if (balance < -1 && num < node->right->key) {
        return 4;
    }
    else
    {
        return 0;
    }

}

struct node* insert(struct node* node, int key) {
    /* 1.  Perform the normal BST rotation */
    if (node == NULL)
        return (newNode(key));

    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    /* 2. Update height of this ancestor node */
    node->height = max(height(node->left), height(node->right)) + 1;

    /* 3. Get the balance factor of this ancestor node to check whether
     this node became unbalanced */
    int balance = getBalance(node);
    int type = checkUnbalancedType(node, key);
    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (type == 1)
        return rightRotate(node);

    // Right Right Case
    if (type == 2)
        return leftRotate(node);

    // Left Right Case
    if (type == 3) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (type == 4) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    /* return the (unchanged) node pointer */
    return node;
}

int displayTree(struct node *root) // inOrder left root right
{
    struct node *ptr = root;
    if (root != NULL) {
    displayTree(root->left);
    printf("%d ", root->key);
    displayTree(root->right);
    }
}

struct node* search(struct node* root,int key) {
  struct node *p= root,*node=NULL;
  do{
    if(p->key==key)
      {  
        node = p;
        printf("\nSearch Found!");
      }
    else if(p->key > key)
      p = p->left;
    else
      p = p->right;
  }while(p != NULL && node == NULL);
  if(node==NULL)
    printf("\nSearch Not Found!");
  return node;
}

int main() {
    struct node *root = NULL,*searched;
    struct node *root2 = NULL;

    /* Constructing tree given in the above figure */
    root = insert(root, 30);
    root = insert(root, 25);
    root = insert(root, 12);
    root = insert(root, 28);
    root = insert(root, 40);
    root = insert(root, 32);
    root = insert(root, 41);
    
  

    /* The constructed AVL Tree would be
      30
     /  \
   20   40
  /  \     \
10  25    50
     */

    printf("In order traversal of the constructed Balanced Binary tree is \n");
    displayTree(root);
    searched = search(root,40);
    if(&searched->left->key != NULL)
    printf("\nLeft is %d",searched->left->key);
    if(&searched->right->key != NULL)
    printf("\nRight is %d",searched->right->key);
    return 0;
}