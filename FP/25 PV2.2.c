#include<stdio.h>
#include<stdlib.h>

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

void pushFront	(int val, linkedList *h){
	node_t *temp = (node_t*) malloc (sizeof(node_t));
	temp->value = val;
	if(h->tail == NULL){
		h->tail = temp;
		temp->next = NULL;
	}
	else{
		temp->next = h->head;
	}	
	h->head = temp;
}

void pushMid	(int val, linkedList *h){
	node_t *temp2;
	int i;
	temp2 = h->head;
	while(temp2->next->value < val){
		temp2 = temp2->next;
	}
	node_t *temp = (node_t*) malloc (sizeof(node_t));
	temp->value = val;
	temp->next = temp2->next;
	temp2->next = temp;
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
	printf("\n");
}

int main(){
	linkedList *h = (linkedList*) malloc (sizeof(linkedList));
	h->head = NULL;
	h->tail = NULL;
	int q, val, max, min;
	q = 0;
	while(q != -1){
		scanf("%d", &q);
		if(q == 1){
			scanf("%d", &val);
			if(h->head == NULL || val <= h->head->value){
				pushFront(val, h);
			}
			else if(val >= h->tail->value){
				pushBack(val, h);
			}
			else{
				pushMid(val, h);
			}
		}
		else if(q == 0){
			if(h->head != NULL) print(h);
		}
	}
}
