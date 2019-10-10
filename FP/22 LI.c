#include<stdio.h>
#include<stdlib.h>
#define new(lul) (lul*) malloc (sizeof(lul))

typedef struct node{
	long long value;
	struct node* right;
	struct node* left;
}node_t;

typedef struct{
	node_t* root;
}tree;

long long counter;
node_t* Insert(node_t *node, long long val){
	if(!node){
		node_t *temp = new(node_t);
		temp->value = val;
		temp->right = NULL;
		temp->left = NULL;
		counter++;
		
		return temp;		
	}
	
	if(val > node->value) node->right = Insert(node->right, val);
	else if(val < node->value) node->left = Insert(node->left, val);
	else return node;
	
	return node;
}

long long Search(node_t *node, long long val){
	if(!node) return 0;
	if(node->value == val) return 1;
	
	if(val > node->value) return Search(node->right, val);
	else return Search(node->left, val);
}

long long count;
void InOrder(node_t *node, long long i){
	if(node){
		InOrder(node->left, i);
		count++;
		if(count == i){
			printf("%lld\n", node->value);
			count = -4294967296;
		}
		InOrder(node->right, i);
	}
}

void InOrder2(node_t *node, long long i){
	if(node){
		InOrder2(node->right, i);
		if(count == i){
			printf("%lld\n", node->value);
			count = 4294967296;
		}
		count--;
		InOrder2(node->left, i);
	}
}

node_t *Delete(node_t *node, long long val){
	if(!node) return NULL;
	if(node->value == val){
		if(!node->left && !node->right){
			free(node);
			counter--;
			return NULL;			
		}
		else if(node->left && !node->right){
			node_t *temp = node->left;
			free(node);
			counter--;
			return temp;
		}
		else if(!node->left && !node->right){
			node_t *temp = node->right;
			free(node);
			counter--;
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
	tree *t = new(tree);
	t->root = NULL;
	long long q, val, i;
	counter = 0;
	count = 0;
	while(1){
		scanf("%lld", &q);
		if(q == -1) return 0;
		else if(q == 1){
			scanf("%lld", &val);
			t->root = Insert(t->root, val);
		}
		else if(q == 2){
			scanf("%lld", &val);
			t->root = Delete(t->root, val);
		}
		else if(q == 3){
			scanf("%lld", &i);
			if(counter >= i){
				if(i >= counter/2){
					count = counter;
					InOrder2(t->root, i);
				}
				else if(i < counter/2){
					count = 0;
					InOrder(t->root, i);
				}
			}
			else printf("-1\n");
		}
	}
	
	return 0;
}
