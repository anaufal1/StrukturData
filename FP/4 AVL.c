#include <stdio.h>
#include <stdlib.h>

/*Mendefinisikan tipe data dari node*/
typedef struct nd{
	int data, height;
	struct nd *left, *right;
} node_t;

/*Melakukan input sekaligus menyeimbangkan tree jika terjadi kondisi dimana tree tidak balance*/
void insertTreeNode(node_t **node, int input); 
int Height(node_t *node); /*Tinggi sebuah node*/
int Max(int a, int b); /*Mencari nilai maksimal dari dua buah nilai*/
void rotateLeft(node_t **node);
void rotateRight(node_t **node);
void rotateLeftRight(node_t **node);
void rotateRightLeft(node_t **node);
void printTreeInOrder(node_t *node);

int main(){
	int banyak_node, a;
	node_t *r;
	r=NULL;
	printf("=========================================================== \n");
	printf("|| Melakukan input sekaligus menyeimbangkan tree jika    ||\n");
	printf("||    terjadi kondisi dimana tree tidak balance          ||\n");
	printf("=========================================================== \n\n");
	printf("======================== AVL ============================== \n\n");
	printf("Masukkan banyak data : ");
	scanf("%d", &banyak_node);
	
	/*Melakukan input data tree*/
	
	while(banyak_node--){
	printf("data node : ");
		scanf("%d", &a);
		insertTreeNode(&r, a);
	
	}
	
	/*Menampilkan tinggi masing-masing node (Membuktikan bahwa tree sudah balance)*/
	printf("\nHasil Bahwa tree sudah balance : \n\n");
	printTreeInOrder(r);
	
	return 0;
}

void insertTreeNode(node_t **node, int input){
	if(*node==NULL){
		*node=(node_t*)malloc(sizeof(node_t));
		(*node)->data=input;
		(*node)->left=(*node)->right=NULL;
	}
	else if(input<=(*node)->data){
		insertTreeNode(&((*node)->left), input);
		/*Jika tinggi node sebelah kiri dikurang tinggi node sebelah kanan sama dengan 2*/
		if(Height((*node)->left)-Height((*node)->right)==2){
			/*Jika data input lebih kecil dari node di sebelah kiri*/
			if(input<=(*node)->left->data)
				rotateRight(&(*node)); /*Rotasi ke arah kanan*/
			/*Jika data input lebih besar dari node di sebelah kiri*/
			else
				rotateLeftRight(&(*node)); /*Rotasi ke arah kiri dan kanan*/
		}
	}
	else{
		/*Jika tinggi node sebelah kanan dikurang tinggi node sebelah kiri sama dengan 2*/
		insertTreeNode(&((*node)->right), input);
		if(Height((*node)->right)-Height((*node)->left)==2){
			/*Jika data input lebih besar dari node di sebelah kanan*/
			if(input>(*node)->right->data)
				rotateLeft(&(*node)); /*Rotasi ke arah kiri
			/*Jika data input lebih kecil dari node di sebelah kiri*/
			else
				rotateRightLeft(&(*node)); /*Rotasi ke arah kanan dan kiri*/
		}
	}
	
	/*Memasukkan tinggi node yang sedang di proses*/
	(*node)->height=Max(Height((*node)->left), Height((*node)->right))+1;
}

int Height(node_t *node){
	/*Jika node yang diperiksa adalah NULL, tingginya adalah -1, selain itu, tingginya tetap*/
	return node == NULL ? -1 : node->height;
}

int Max(int a, int b){
	/*Membandingkan antara nilai a dan b, kembalikan nilai yang paling besar*/
	return a<b ? b : a;
}

void rotateRight(node_t **node){
	/*printf("Rotate Right %d\n", (*node)->data); */
	node_t *tmp=(*node)->left;
	(*node)->left=tmp->right;
	tmp->right=(*node);
	/*Mengupdate tinggi node setelah rotasi*/
	(*node)->height=Max(Height((*node)->left), Height((*node)->right))+1;
	tmp->height=Max(Height(tmp->left), (*node)->height)+1;
	/*Menentukan root baru*/
	*node=tmp;
}

void rotateLeft(node_t **node){
	/*printf("Rotate Left %d\n", (*node)->data);*/
	node_t *tmp=(*node)->right;
	(*node)->right=tmp->left;
	tmp->left=(*node);
	/*Mengupdate tinggi node setelah rotasi*/
	(*node)->height=Max(Height((*node)->left), Height((*node)->right))+1;
	tmp->height=Max(Height(tmp->right), (*node)->height)+1;
	/*Menentukan root baru*/
	*node=tmp;
}

void rotateLeftRight(node_t **node){
	rotateLeft(&((*node)->left));
	rotateRight(&(*node));
}

void rotateRightLeft(node_t **node){
	rotateRight(&((*node)->right));
	rotateLeft(&(*node));
}

void printTreeInOrder(node_t *node){
	if(node==NULL){
		return;
	}
	/*Melakukan print tinggi masing-masing node*/
	printTreeInOrder(node->left);
	printf("Data=%d Height=%d\n", node->data, node->height);
	printTreeInOrder(node->right);
}

/*
Jumlah Data 11
data node 
1 26 2 25 3 24 4 23 5 22 6
*/
