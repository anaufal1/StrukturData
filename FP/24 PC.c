#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
	char name[30];
	struct node *next;
}node_t;

typedef struct{
	node_t *first;
	node_t *last;
}queue;

void push(char nama[30], queue *q){
	node_t *temp = (node_t*) malloc (sizeof(node_t));
	strcpy(temp->name, nama);
	temp->next = NULL;
	if(q->first == NULL) q->first = temp;
	else q->last->next = temp;
	q->last = temp;
}

void pop(queue *q){
	if(!q->first) return;
	node_t *temp;
	temp = q->first;
	q->first = q->first->next;
	free(temp);
}


int main	(){
	queue *q = (queue*) malloc (sizeof(queue));
	q->first = NULL;
	q->last = NULL;
	
	int i, qu, counter;
	char nama[30];
	
	while(1){
		counter = 0;
		scanf("%d", &qu);
		if(qu == -1) break;
		else if(qu == 1){
			scanf("%s", nama);
			push(nama, q);
		}
		else if(qu == 2){
			scanf("%s", nama);
			while(1){
				if(!q->first){
					counter = -1;
					break;
				}
				if(strcmp(q->first->name, nama) == 0){
					break;
				}
				pop(q);
				counter++;
			}
			printf("%d\n", counter);
		}
	}
	return 0;
}
