#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define new(lul) (lul*) malloc (sizeof(lul))
#define clrscr system("CLS")
#define pause system("pause")
#define judul printf("-----------------------PROGRAM TENTANG-----------------------\n----------------------------QUEUE----------------------------\n\n")

typedef struct node{
	int value;
	struct node* next;
}node_t;

typedef struct{
	node_t *first;
	node_t *last;
}queue;

int max_val, min_val, val_kuadrat = 0, sigma_val = 0, counter = 0;
double avg_val;

void push(queue *q){
	clrscr;
	judul;
	node_t *temp = new(node_t);
	printf("Masukkan data yang ingin diinput ke queue : ");
	int val;
	scanf("%d", &val);
	temp->value = val;
	temp->next = NULL;
	if(q->first == NULL)	q->first = temp;
	else q->last->next = temp;
	q->last = temp;
	val_kuadrat += val*val;
	sigma_val += val;
	counter++;
}

void pop(queue *q){
	clrscr;
	judul;
	if(!q->first){
		printf("Data kosong nak\n");
		pause;
		return;
	}
	node_t *temp;
	temp = q->first;
	q->first = temp->next;
	val_kuadrat -= temp->value * temp->value;
	sigma_val -= temp->value;
	free(temp);
	printf("Data terdepan sudah terhapus\n");
	pause;
	counter--;
}

void print(queue *q){
	clrscr;
	judul;
	node_t *temp;
	if(!q->first){
		printf("Data kosong nak\n");
		pause;
		return;
	}
	temp = q->first;
	int z = 0;
	while(temp){
		if(z != 0) printf("->");
		printf("%d", temp->value);
		temp = temp->next;
		z++;
	}
	printf("\n");
	pause;
}

void max(queue *q){
	clrscr;
	judul;
	if(!q->first){
		printf("Data kosong nak\n");
		pause;
		return;
	}
	node_t *temp = new(node_t);
	temp = q->first;
	int z = 0;
	while(temp){
		if(z == 0 || temp->value > max_val) max_val = temp->value;
		temp = temp->next;
		z++;
	}
	printf("Data terbesar dalam queue adalah : %d\n", max_val);
	pause;
}

void min(queue *q){
	clrscr;
	judul;
	if(!q->first){
		printf("Data kosong nak\n");
		pause;
		return;
	}
	node_t *temp = new(node_t);
	temp = q->first;
	int z = 0;
	while(temp){
		if(z == 0 || temp->value < min_val) min_val = temp->value;
		temp = temp->next;
		z++;
	}
	printf("Data terkecil dalam queue adalah : %d\n", min_val);
	pause;
}

void avg(queue *q){
	clrscr;
	judul;
	if(!q->first){
		printf("Data kosong nak\n");
		pause;
		return;
	}
	node_t *temp = new(node_t);
	temp = q->first;
	int jumlah = 0, z = 0;
	while(temp){
		z++;
		jumlah += temp->value;
		temp = temp->next;
	}
	avg_val = (double) jumlah / z;
	printf("Rata-rata dari data dalam queue adalah : %.2f\n", avg_val);
	pause;
}

void stddev(queue *q){
	clrscr;
	judul;
	double stdev;
	stdev = (double)((counter*val_kuadrat)-(sigma_val*sigma_val))/(counter*(counter-1));
	stdev = sqrt(stdev);
	printf("Standar deviasi dari data dalam queue adalah : %.2f\n", stdev);
	pause;
}

void clear(queue *q){
	clrscr;
	judul;
	while(1){
		if(!q->first) break;
		node_t *temp;
		temp = q->first;
		q->first = q->first->next;
		free(temp);
	}
	printf("Data dari queue sudah terhapus semua\n");
	pause;
}

int i;
char y;
void menu(queue *q){
	clrscr;
	judul;
	printf("1. Tambah data ke queue\n"); 					//49
	printf("2. Pop data dari queue\n"); 					//50
	printf("3. Cari data terbesar dari queue\n"); 			//51
	printf("4. Cari data terkecil dari queue\n"); 			//52
	printf("5. Cari rata-rata dari data queue\n"); 			//53
	printf("6. Cari standar deviasi dari data queue\n"); 	//54
	printf("7. Hapus semua data queue\n"); 					//55
	printf("8. Print semua data queue\n");					//56
	printf("9. Keluar dari program\n"); 					//57
	printf("Pilih menu yang kamu inginkan : ");
	i = getch();
	if(i == 49) push(q);
	else if(i == 50) pop(q);
	else if(i == 51) max(q);
	else if(i == 52) min(q);
	else if(i == 53) avg(q);
	else if(i == 54) stddev(q);
	else if(i == 55) clear(q);
	else if(i == 56) print(q);
	else if(i == 57){
		clrscr;
		judul;
		printf("Yakin mau keluar? (y/n) : ");
		scanf(" %c", &y);
	}
}

int main(){
	queue *q = new(queue);
	q->first = NULL;
	q->last = NULL;
	
	while(y != 'y'){
		menu(q);
	}
	
	return 0;
}
