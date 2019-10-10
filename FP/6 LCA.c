#include <stdio.h>
#include <stdlib.h>

/*Mendefinisikan tipe data sebuah node*/
typedef struct nd{
	int data, height;
	struct nd *left, *right;
} node_t;

void insertTreeNode(node_t **node, int input);	/*Fungsi untuk menambah sebuah node */
void findLCA(node_t *node, int a, int b);		/*Fungsi untuk menemukan LCA dari dua buah node */

int main(){
	int banyak_node, testcase, a, b;
	node_t *root; /*Pointer yang menunjuk root tree */
	root=NULL;
	printf("Program ini berfungsi untuk mencari LCA dari \n");
	printf("dua buah node dalam sebuah BST\n");
	printf("=============================================\n\n");
	printf("masukan jumlah data : ");
	scanf("%d", &banyak_node);
	/*Memasukkan data/node dari tree */
	while(banyak_node--){
	printf("\nmasukkan nilai node/data: ");
		scanf("%d", &a);
		insertTreeNode(&root, a);
	}
	
	/*Memasukkan banyaknya kasus yang ingin dicoba */
	printf("\nmasukan banyak kasus : ");
	scanf("%d", &testcase);
	while(testcase--){
		printf("\nmenginputkan 2 buah node untuk dicari LCA : \n");
		scanf("%d %d", &a, &b); /*Menginputkan dua buah node untuk dicari LCAnya*/
		findLCA(root, a, b);		/*Memanggil fungsi untuk mencari LCA*/
	}
	
	return 0;
}

void insertTreeNode(node_t **node, int input){
	if(*node==NULL){
		*node=(node_t*)malloc(sizeof(node_t));
		(*node)->data=input;
		(*node)->left=(*node)->right=NULL;
	}
	else if(input<=(*node)->data)
		insertTreeNode(&((*node)->left), input);
	else
		insertTreeNode(&((*node)->right), input);
	
	return;
}

void findLCA(node_t *node, int a, int b){
	/*Jika salah satu pernyataan di bawah ini benar, maka node itulah LCAnya*/
	if(	a<=node->data && b>node->data ||
		b<=node->data && a>node->data ||
		a==node->data && b<node->data ||
		b==node->data && a<node->data)
		printf("\nLCA : %d\n", node->data); /*Menampilkan LCA*/
		
	/*Jika nilai yang dicari keduanya lebih kecil dari node yang diperiksa */
	else if(a<node->data && b<node->data)
		findLCA(node->left, a, b); 	/*Periksa node sebelah kiri
		
	/*Jika nilai yang dicari keduanya lebih besar dari node yang diperiksa*/
	else if(a>node->data && b>node->data)
		findLCA(node->right, a, b);	/*Periksa node sebelah kanan*/
}
