#include<stdio.h>
#include<stdlib.h>
#define new(lul) (lul*) malloc (sizeof(lul))

typedef struct node{
	int value;
	struct node* right;
	struct node* left;
}node_t;

typedef struct{
	node_t* root;
}tree;

node_t* Insert(node_t *node, int val){
	if(!node){
		node_t *temp = new(node_t);
		temp->value = val;
		temp->right = NULL;
		temp->left = NULL;

		return temp;		
	}
	
	if(val > node->value) node->right = Insert(node->right, val);
	else node->left = Insert(node->left, val);
	
	return node;
}

void Search(node_t *node, int val){
	node_t *temp = node;
	while(1){
		if(!temp){
			printf("Tidak ada\n");
			return;
		}
		if(temp->value == val){
			printf("Ada\n");
			return;
		}
		
		if(val >= temp->value){
			printf("kanan\n");
			temp = temp->right;
		}
		else if(val < temp->value){
			printf("kiri\n");
			temp = temp->left;
		}
	}
}

void InOrder(node_t *node){
	if(node){
		InOrder(node->left);
		printf("%d ", node->value);
		InOrder(node->right);
	}
}

void PreOrder(node_t *node){
	if(node){
		printf("%d ", node->value);
		PreOrder(node->left);
		PreOrder(node->right);
	}
}

void PostOrder(node_t *node){
	if(!node) return;
	if(node){
		PostOrder(node->left);
		PostOrder(node->right);
		printf("%d ", node->value);
	}
}

node_t *Delete(node_t *node, int val){
	if(!node) return NULL;
	if(node->value == val){
		if(!node->left && !node->right){
			free(node);
			return NULL;			
		}
		if(node->left && !node->right){
			node_t *temp = node->left;
			free(node);
			return temp;
		}
		if(!node->left && !node->right){
			node_t *temp = node->right;
			free(node);
			return temp;
		}
		node_t *temp= node->right;
		while(temp->left){
			temp = temp->left;
		}
		node->value = temp->value;
		node->right = Delete(node->right,node->value);
	}
	if(val>node->value){
		node->right = Delete(node->right,val);
	}
	else{
		node->left = Delete(node->left,val);
	}
}

int main(void){
	printf("-----------------------------BST PROGRAM-----------------------------\n\n");
	printf("How to use :\n\t-Input query 1 x : inserting x (int) to the tree\n\t-Input query 2 x : searching x (int) from the tree\n\t-Input query 3 x : deleting x (int) from the tree\n\t-Input query 4   : printing the Pre Order, In Order, and Post Order of the tree\n\t-Input query -1  : exiting the program\n");
	printf("Sample Input\n");
	printf("   1 5\n   1 7\n   1 9\n   1 3\n   1 4\n   4\n   1 8\n   2 4\n   4\n   3 7\n   4\n   -1\n");
	printf("Sample Ourput\n");
	printf("   Pre Order : 5 3 4 7 9 \n   In Order : 3 4 5 7 9 \n   Post Order : 4 3 9 7 5 \n   Tydac Ketemu\n   Pre Order : 5 3 4 7 9 8 \n   In Order : 3 4 5 7 8 9\n   Post Order : 4 3 8 9 7 5 \n   Pre Order : 5 3 4 8 9 \n   In Order : 3 4 5 8 9 \n   Post Order : 4 3 9 8 5\n\n");
	tree *t = new(tree);
	t->root = NULL;
	int q, val, flag;
	
	while(1){
		scanf("%d", &q);
		if(q == -1) return 0;
		else if(q == 1){
			scanf("%d", &val);
			t->root = Insert(t->root, val);
		}
		else if(q == 2){
			scanf("%d", &val);
			Search(t->root, val);
		}
		else if(q == 3){
			scanf("%d", &val);
			t->root = Delete(t->root, val);
		}
		else if(q == 4){
			printf("Pre Order : ");
			PreOrder(t->root);
			printf("\n");
			printf("In Order : ");
			InOrder(t->root);
			printf("\n");
			printf("Post Order : ");
			PostOrder(t->root);
			printf("\n");
		}
	}
	
	return 0;
}
