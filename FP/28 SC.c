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
	
	if(val >= node->value) node->right = Insert(node->right, val);
	else if(val < node->value) node->left = Insert(node->left, val);
	else return node;
	
	return node;
}

void InOrder(node_t *node){
	if(node){
		InOrder(node->right);
		printf(" %d", node->value);
		InOrder(node->left);
	}
}

void PreOrder(node_t *node){
	if(node){
		printf(" %d", node->value);
		PreOrder(node->right);
		PreOrder(node->left);
	}
}

void PostOrder(node_t *node){
	if(node){
		PostOrder(node->right);
		PostOrder(node->left);
		printf(" %d", node->value);
	}
}

int main(void){
	tree *t = new(tree);
	t->root = NULL;
	int q, val, i;
	
	scanf("%d", &q);
	for(i = 0; i < q; i++){
		scanf("%d", &val);
		t->root = Insert(t->root, val);
	}
	printf("Pre order :");
	PreOrder(t->root);
	printf("\n");
	printf("In order  :");
	InOrder(t->root);
	printf("\n");
	printf("Post order:");
	PostOrder(t->root);
	printf("\n");
	
	return 0;
}
