#include <stdio.h>
#include <stdlib.h>

/*Mendefinisikan tipe data sebuah node*/
typedef struct nd{
	int data, height;
	struct nd *left, *right;
} node_t;

void insertTreeNode(node_t **node, int input);		/*Fungsi untuk memasukkan sebuah node*/
void FindPath(node_t *node, int find, int *flag);	/*Mencari sebuah nilai dan path pencariannya*/

int main(){
	int testcase, banyak_node, a, b;
	node_t *root;
	root=NULL;
	printf("masukkan jumlah data dari tree : ");
	scanf("%d", &banyak_node);
	/*Memasukkan node/data dari tree	*/
	while(banyak_node--){
		scanf("%d", &a);
		insertTreeNode(&root, a);
	}
	
	/*Banyaknya kasus yang ingin dicoba*/
	printf("berapa kali data yang ingin di coba : \n");
	scanf("%d", &testcase);
	while(testcase--){
		int flag;				/*Kondisi data ditemukan atau tidak*/
		printf("nilai yang ingin di cari : ");
		scanf("%d", &a);		/*Nilai yang ingin dicari*/
		if(root!=NULL)
		FindPath(root, a, &flag);	/*Memanggil fungsi untuk mencari data
		/*
		  Jika data ditemukan tampilkan "Data ditemukan", kalau tidak
		  tampilkan "Data tidak ditemukan"
		*/
		printf("%s\n", flag ? "Data ditemukan" : "Data tidak ditemukan");
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
}

void FindPath(node_t *node, int find, int *flag){
	printf("%d\n", node->data); /*Menampilkan isi node*/
	
	if(find==node->data) /*Jika node yang diperiksa sama dengan nilai yang dicari*/
		*flag=1; /*Data ditemukan*/
	
	/*Jika kondisi seperti ini, data tidak ditemukan*/
	else if((find<node->data && node->left==NULL)||
			(find>node->data && node->right==NULL))
			*flag=0; /*Data tidak ditemukan*/
	
	/*Jika data yang dicari lebih kecil dari node yang sedang diperiksa*/
	else if(find<node->data)
		FindPath(node->left, find, flag); /*Periksa node sebelah kiri*/

	/*Jika data yang dicari lebih besar dari node yang sedang diperiksa*/
	else if(find>node->data)
		FindPath(node->right, find, flag); /*Periksa node sebelah kanan*/
}
