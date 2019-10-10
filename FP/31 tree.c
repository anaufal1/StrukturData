#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define new(lul) (lul*) malloc (sizeof(lul))
#define clrscr system("CLS")
#define pause system("pause")
#define judul printf("---------------------------------------PROGRAM TREE---------------------------------------\n\n");

typedef struct node{
	int value;
	struct node* right;
	struct node* left;
	char nama[50];
}node_t;

void newNode(node_t **node, int val, char name[]){
	node_t *temp = new(node_t);
		temp->value = val;
		strcpy(temp->nama, name);
		temp->right = NULL;
		temp->left = NULL;
		*node = temp;
		return;
}

void Insert(node_t **node, int val, char name[]){
	if(!(*node)){
		newNode(node, val, name);
		return;		
	}
	
	if(val > (*node)->value) Insert(&(*node)->right, val, name);
	else if(val < (*node)->value) Insert(&(*node)->left, val, name);
	
}

void InOrder(node_t *node){
	if(node){
		InOrder(node->left);
		printf("-NRP\t: %d\n Nama\t: %s\n", node->value, node->nama);
		InOrder(node->right);
	}
}

void PreOrder(node_t *node){
	if(node){
		printf("-NRP\t: %d\n Nama\t: %s\n", node->value, node->nama);
		PreOrder(node->left);
		PreOrder(node->right);
	}
}

void PostOrder(node_t *node){
	if(node){
		PostOrder(node->left);
		PostOrder(node->right);
		printf("-NRP\t: %d\n Nama\t: %s\n", node->value, node->nama);
	}
}

int main(void){
	node_t *root = new(node_t);
	root = NULL;
	int q, val;
	char name[50];
	
	while(1){
		judul;
		printf("MENU:\n\n");
		printf("   -Input 1 untuk masuk ke menu penambahan\n");
		printf("   -Input 2 untuk mencetak semua data\n");
		printf("   -Input -1 untuk keluar program\n\n");
		printf("Input : ");
		scanf("%d", &q);
		clrscr;
		if(q == -1){
			judul;
			printf("Goodbye...\nHave a nice day ^^\n\n\n\n\n");
			return 0;
		}
		else if(q == 1){
			printf("Menu penambahan data\n\n");
			printf("Masukkan NRP : ");
			scanf("%d", &val);
			printf("Masukkan Nama Mahasiswa : ");
			getchar();
			gets(name);
			
			Insert(&root, val, name);
		}
		else if(q == 2){
			judul;
			printf("Pre Order :\n");
			PreOrder(root);
			printf("\n");
			printf("In Order :\n");
			InOrder(root);
			printf("\n");
			printf("Post Order :\n");
			PostOrder(root);
			printf("\n");
		}
		else printf("Mavok lu nak\n");
		pause;
		clrscr;
	}
	
	return 0;
}
