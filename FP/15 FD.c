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

void Search(node_t *node, int val){
	node_t* temp = node;
	node_t* parent = NULL;
	node_t* rightChild = node->right;
	node_t* leftChild = node->left;
	while(1){
		if(!temp){
			printf("-1\n");
			return;
		}
		if(val > temp->value){
			parent = temp;
			temp = temp->right;
			if(temp){
				rightChild = temp->right;
				leftChild = temp->left;
			}
		}
		else if(val < temp->value){
			parent = temp;
			temp = temp->left;
			if(temp){
				rightChild = temp->right;
				leftChild = temp->left;
			}
		}
		else{
			if(leftChild) printf("%d ", leftChild->value);
			else printf("-1 ");
			
			if(rightChild) printf("%d ", rightChild->value);
			else printf("-1 ");
			
			if(parent) printf("%d", parent->value);
			else printf("-1");
			
			break;
		}
	}
	printf("\n");
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
	
	scanf("%d", &q);
	for(i = 0; i < q; i++){
		scanf("%d", &val);
		if(t->root){
			Search(t->root, val);
		}
		else printf("-1\n");
	}
	
	return 0;
}
