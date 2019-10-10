#include<stdio.h>
#include<stdlib.h>
#define MAX_STACK 10

typedef struct{
	int top;
	int data[MAX_STACK];
}stack;
stack tumpuk;

void inisialisasi(){
	tumpuk.top = -1;
}

int isFull(){
	return (tumpuk.top == MAX_STACK -1) ? 1 : 0;
}

int isEmpty(){
	return (tumpuk.top == -1) ? 1 : 0;
}

void push(int val){
	tumpuk.data[++tumpuk.top] = val;
}

void pop(){
	printf("Data terambil %d\n", tumpuk.data[tumpuk.top]);
	tumpuk.top--;
	system("pause");
}

void tampilStack(){
	int i;
	for(i = tumpuk.top; i >= 0; i--){
		printf("Data stack ke-%d adalah %d\n", i, tumpuk.data[i]);
	}
	system("pause");
}

void masukkanData(){
	int val;
	printf("Masukkan data: ");
	scanf("%d", &val);
	push(val);
	system("pause");
}

void ambilData(){
	while(!isEmpty()){
		pop();
	}
}

int i;
void menu(){
	system("CLS");
	printf("---------------------------------------------------------------------\n");
	printf("|---------------------------PROGRAM STACK----------------------------\n");
	printf("---------------------------------------------------------------------\n\n");
	printf("NB: Stack dalam program ini bermemori 10 stack\n");
	printf("Pilih Menu :\n");
	printf("1. Tambah data ke stack\n2. Ambil data teratas dari stack\n3. Hapus semua data stack\n4. Print stack\n5. Keluar\n");
	scanf("%d", &i);
	if(i == 1){
		masukkanData();
	}
	else if(i == 2){
		pop();
	}
	else if(i == 3){
		ambilData();
	}
	else if(i == 4){
		tampilStack();
	}
	else if(i == 5){
		return;
	}
	else{
		printf("Mabok lu tjoy\n");
		system("pause");
	}
}

int main(){
	inisialisasi();
	while(i!=5){
		menu();
	}
	return 0;
}
