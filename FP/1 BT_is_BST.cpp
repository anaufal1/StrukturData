
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <limits.h>

using namespace std;
 
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
 
int isBSTUtil(struct node* node, int min, int max);
 
/* Returns true if the given tree is a binary search tree
 (efficient version). */
int isBST(struct node* node)
{
  return(isBSTUtil(node, INT_MIN, INT_MAX));
}
 
/* Returns true if the given tree is a BST and its
   values are >= min and <= max. */
int isBSTUtil(struct node* node, int min, int max)
{
 
  /* an empty tree is BST */
  if (node==NULL)
     return 1;
       
  /* false if this node violates the min/max constraint */ 
  if (node->data < min || node->data > max)
     return 0;
 
  /* otherwise check the subtrees recursively,
   tightening the min or max constraint */
  return
    isBSTUtil(node->left, min, node->data-1) &&  // Allow only distinct values
    isBSTUtil(node->right, node->data+1, max);  // Allow only distinct values
}
 
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}
 
/*            FUNGSI UTAMA            */
int main()
{
  /* Contoh
  				6
  			  /	 \
             2    8
            / \
		   1   4
		      /
			 3  
		   
		   	*/ 
	
  cout<<"------------ Membuktikan BT = Binary Search Tree ------------"
  <<endl<<endl;
  
  //Bisa ditambahkan kondisi Tree disini
  struct node *root   	  = newNode(6);
  root->left         	  = newNode(2);
  root->right       	  = newNode(8);
  root->left->left  	  = newNode(1);
  root->left->right 	  = newNode(4);
  root->left->right->left = newNode(3);
  
  printf(" struct node *root   	  = newNode(6); \n");
  printf(" root->left         	  = newNode(2);\n");
  printf(" root->right       	  = newNode(8);\n");
  printf(" root->left->left  	  = newNode(1);\n");
  printf(" root->left->right 	  = newNode(4);\n");
  printf(" root->left->right->left = newNode(3);  \n\n");
  if(isBST(root))
    printf(" BT ini adalah BST");
  else
    printf("   BT ini bukan BST");
     
  getchar();
  return 0;
}
