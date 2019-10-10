#include<stdio.h>
#include<stdlib.h>
#define new(lul) (lul*) malloc (sizeof(lul))

typedef struct node{
	int value;
	struct node *next;
	struct node *prev;
}node_t;

typedef struct{
	node_t *head;
	node_t *tail;
}linkedList;

void init(linkedList *h){
	h->head = NULL;
	h->tail = NULL;
}

void pushBack	(int val, linkedList *h){
	node_t *temp = new(node_t);
	temp->value = val;
	temp->next = NULL;
	if(h->head == NULL){
		temp->prev = NULL;
		h->head = temp;
	}
	else{
		temp->prev = h->tail;
		h->tail->next = temp;
	}
	h->tail = temp;
}

void pushFront	(int val, linkedList *h){
	node_t *temp = new(node_t);
	temp->value = val;
	temp->prev = NULL;
	if(h->tail == NULL){
		h->tail = temp;
		temp->next = NULL;
	}
	else{
		h->head->prev = temp;
		temp->next = h->head;
	}	
	h->head = temp;
}

void pushMid	(int val, int index, linkedList *h){
	node_t *temp2 = new(node_t);
	int i;
	if(index <= 1){
		pushFront(val, h);
		return;
	}
	temp2 = h->head;
	for(i = 1; i < index - 1 && temp2 != NULL; i++){
		temp2 = temp2->next;
	}
	if(temp2 == NULL){
		pushBack(val, h);
		return;
	}
	else{
		node_t *temp = new(node_t);
		temp->value = val;
		temp->next = temp2->next;
		temp->prev = temp2->prev;
		temp2->next->prev = temp;
		temp2->next = temp;
		if(temp->next == NULL){
			h->tail = temp;
		}
	}
}

void popFront(linkedList* h){
	if(!h->head){
		printf("Data Kosong Nak\n");
		return;
	}
	node_t *temp;
	temp = h->head;
	h->head = h->head->next;
	if(h->head) h->head->prev = NULL;
	free(temp);
}

void popBack(linkedList* h){
	if(!h->head){
		printf("Data Kosong Nak\n");
		return;
	}
	node_t *temp;
	temp = h->tail;
	h->tail = h->tail->prev;
	if(h->tail) h->tail->next = NULL;
	free(temp);
}

void popMid		(int index, linkedList *h){
	node_t *temp;
	int i;
	temp = h->head;
	if(h->head->value == index){
		popFront(h);
		return;
	}
	else if(h->tail->value == index){
		popBack(h);
		return;
	}
	while(temp != NULL){
		if(temp->next->value == index) break;
		temp = temp->next;
		if(temp->next == NULL){
			return;
		}
	}
	if(temp == NULL){
		return;
	}
	else{
		node_t *temp2;
		temp2 = temp->next;
		temp->next = temp2->next;
		if(temp->next == NULL){
			h->tail = temp;
		}
		else temp2->next->prev = temp;
		free(temp2);
	}
}

void print	(linkedList* h){
	node_t *temp;
	int i;
	temp = h->head;
	i = 0;
	if(!h->head) printf("Data Kosong Nak");
	while(temp != NULL){
		if(i != 0){
			printf(" ");
		}
		printf("%d", temp->value);
		temp = temp->next;
		i++;
	}
	printf("\n");
}

void printReverse	(linkedList* h){
	node_t *temp;
	int i;
	temp = h->tail;
	i = 0;
	if(!h->head) printf("Data Kosong Nak");
	while(temp != NULL){
		if(i != 0){
			printf(" ");
		}
		printf("%d", temp->value);
		temp = temp->prev;
		i++;
	}
	printf("\n");
}

void clear(linkedList *h){
	while(1){
		if(!h->head) return;
		popFront(h);
	}
}

void search(int index, linkedList *h){
	if(!h->head){
		printf("Data kosong nak\n");
		return;
	}
	node_t *temp = h->head;
	if(h->head->value == index){
		printf("Ada\n");
		return;
	}
	else if(h->tail->value == index){
		printf("Ada\n");
		return;
	}
	while(1){
		if(temp->value == index){
			printf("Ada\n");
			return;
		}
		temp = temp->next;
		if(temp == NULL){
			printf("Tidak ada\n");
			return;
		}
	}
}

int main		(){
	linkedList *h = new(linkedList);
	
	init(h);
	printf("-------------------------------------PROGRAM DOUBLE LINKED LIST-------------------------------------\n\n");
	printf("Petunjuk penggunaan :\n");
	printf("   -Input -1 untuk keluar program\n   -Input 1 x untuk memasukkan data (int)x ke belakang list\n   -Input 2 x untuk memasukkan data (int) x ke depan list\n   -Input 3 x i untuk memasukkan data (int) x ke index ke i dari list\n   -Input 4 untuk menghapus data terdepan dari list\n   -Input 5 untuk menghapus data terbelakang dari list\n   -Input 6 x untuk menghapus data (int) x yang terdepan dari list\n   -Input 7 untuk mencetak semua data di list\n   -Input 8 untuk menghapus semua data list\n   -Input 9 x untuk mencari data (int) x dari list\n   -Input 10 untuk mencetak data dari list secara terbalik\n\n");
	int q, val, i;
	
	while(1){
		scanf("%d", &q);
		if(q == -1) break;
		else if(q == 1){
			scanf("%d", &val);
			pushBack(val, h);
		}
		else if(q == 2){
			scanf("%d", &val);
			pushFront(val, h);
		}
		else if(q == 3){
			scanf("%d %d", &val, &i);
			pushMid(val, i, h);
		}
		else if(q == 4){
			popFront(h);
		}
		else if(q == 5){
			popBack(h);
		}
		else if(q == 6){
			scanf("%d", &val);
			popMid(val, h);
		}
		else if(q == 7){
			print(h);
		}
		else if(q == 8){
			clear(h);
		}
		else if(q == 9){
			scanf("%d", &val);
			search(val, h);
		}
		else if(q == 10){
			printReverse(h);
		}
		else{
			printf("Wah.. mabok ni anak\n");
		}
	}
	return 0;
	
}
