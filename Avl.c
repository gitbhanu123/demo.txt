#include <stdio.h> 
#include <stdlib.h> 
struct AVL 
{ 
 int key; 
 struct AVL *left; 
 struct AVL *right; 
 int height; 
}; 
typedef struct AVL node;
int getHeight(node *n){ 
 if(n==NULL) 
 return 0; 
 return n->height; 
} 
node *createNode(int key)
{ 
 node* n = (node *) malloc(sizeof(node)); 
 n->key = key; 
 n->left = NULL; 
 n->right = NULL; 
 n->height = 1; 
 return n; 
} 
int max (int a, int b)
{ 
 return (a>b)?a:b; 
} 
int getBalanceFactor(node * n)
{ 
 if(n==NULL)
 { 
 return 0; 
 } 

 return getHeight(n->left) - getHeight(n->right); 
} 
node* leftRotate(node* y)
{ 
 node* x = y->left; 
 node* T2 = x->right; 
 x->right = y;
 y->left = T2; 
 x->height = max(getHeight(x->right), getHeight(x->left)) + 1; 
 y->height = max(getHeight(y->right), getHeight(y->left)) + 1; 
 return x; 
} 
node* rightRotate(node* x)
{ 
 node* y = x->right; 
 node* T2 = y->left; 
 y->left = x; 
 x->right = T2; 
 x->height = max(getHeight(x->right), getHeight(x->left)) + 1; 
 y->height = max(getHeight(y->right), getHeight(y->left)) + 1; 
 return y; 
} 
node *insert(node* n, int key)
{ 
if (n == NULL) 
 return createNode(key); 
 if (key < n->key) 
 n->left = insert(n->left, key); 
 else if (key > n->key) 
 n->right = insert(n->right, key); 
 n->height = 1 + max(getHeight(n->left), getHeight(n->right)); 
 int bf = getBalanceFactor(n);
 if(bf>1 && key < n->left->key)
 { 
 return leftRotate(n); 
 } 
 if(bf<-1 && key > n->right->key)
{ 
 return rightRotate(n); 
 } 
 if(bf>1 && key > n->left->key)
{ 
 n->left = rightRotate(n->left); 
 return leftRotate(n); 
 } 
 if(bf<-1 && key < n->right->key)
{ 
 n->right = leftRotate(n->right); 
 return rightRotate(n); 
 } 
 return n; 
} 
void printtree(node *root, int space,int n)
{
int i;
 if (root == NULL)
 return;
 space +=n; 
 printtree(root->right, space,n);
 printf("\n");
 for (i =n; i < space; i++)
 printf(" ");
 printf("(%d)\n", root->key);
 printtree(root->left, space,n);
}
int main()
{ 
node * root = NULL; 
 int n,i,key;
 printf("enter the number of nodes\n");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
 printf("enter the key\n");
 scanf("%d",&key);
 root = insert(root, key);
} 
 printtree(root, 0, n) ;
return 0; 
}
