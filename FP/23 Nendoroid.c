#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
	int value;
	struct node *next;
}node_t;

typedef struct{
	node_t *head;
	node_t *tail;
}linkedList;

void pushBack	(int val, linkedList *h){
	node_t *temp = (node_t*) malloc (sizeof(node_t));
	temp->value = val;
	temp->next = NULL;
	if(h->head == NULL)	h->head = temp;
	else h->tail->next = temp;
	h->tail = temp;
}

void popFront	(linkedList *h){
	node_t *temp;
	temp = h->head;
	h->head = h->head->next;
	free(temp);
}

void popBack	(linkedList *h){
	node_t *temp;
	node_t *temp2;
	temp = h->head;
	while(temp->next->next != NULL){
		temp = temp->next;
	}
	temp2 = h->tail;
	h->tail = temp;
	h->tail->next = NULL;
	free(temp2);
}

void print		(linkedList*h){
	node_t *temp;
	int i;
	temp = h->head;
	i = 0;
	while(temp != NULL){
		if(i != 0){
			printf(" ");
		}
		printf("%d", temp->value);
		temp = temp->next;
		i++;
	}
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
		node_t *temp2 = (node_t*) malloc (sizeof(node_t));
		temp2 = temp->next;
		temp->next = temp2->next;
		if(temp->next == NULL){
			h->tail = temp;
		}
		free(temp2);
	}
}

int main(){
	linkedList *h = (linkedList*) malloc (sizeof(linkedList));
	h->head = NULL;
	h->tail = NULL;
	int i, j, temp, a, b[1000], c, d, e;
	char arr[1000];
	scanf("%d %d", &c, &a);
	for(i = 0; i < a; i++){
		scanf("%d", &b[i]);
	}
	for(i = 0; i < a; i++){
		temp = b[i];
		for(j = i + 1; j < a; j++){
			if(temp > b[j]){
				temp = b[j];
				b[j] = b[i];
				b[i] = temp;
			}
		}
	}
	for(i = 0; i < a; i++){
		pushBack(b[i], h);
	}
	for(i = 0; i < c; i++){
		scanf("%s", arr);
		if(strcmp(arr, "ambil_depan")==0){
			popFront(h);
		}
		else if(strcmp(arr, "ambil_belakang")==0){
			popBack(h);
		}
		else if(strcmp(arr, "ambil_tengah")==0){
			scanf("%d", &e);
			popMid(e, h);
		}
		getchar();
	}
	print(h);
	printf("\n");
	return 0;
}
