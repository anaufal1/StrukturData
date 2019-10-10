#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	long long value;
	struct node *down;
}node_t;

typedef struct{
	node_t *top;
}stack;

void push(long long val, stack* s){
	node_t *temp = (node_t*) malloc (sizeof(node_t));
	temp->value = val;
	temp->down = s->top;
	s->top = temp;
}

void pop(stack *s){
	if(!s->top) return;
	node_t* temp;
	temp = s->top;
	s->top = s->top->down;
	free(temp);
}

void clear(stack *s){
	while(1){
		if(!s->top) return;
		pop(s);
	}
}

int main(){
	stack *s = (stack*) malloc (sizeof(stack));
	s->top = NULL;
	
	long long i, j, n, q, c, counter;
	long long val;
	
	scanf("%lld", &n);
	
	for(i = 0; i < n; i++){
		counter = 0;
		scanf("%lld", &q);
		for(j = 0; j < q; j++){
			scanf("%lld", &val);
			push(val, s);
		}
		scanf("%lld", &c);
		if(q == 0){
			counter = -1;
			printf("%lld\n", counter);
			continue;
		}
		while(s->top->value != c){
			pop(s);
			if(!s->top){
				counter = -1;
				break;
			}
			counter++;
		}
		printf("%lld\n", counter);
		clear(s);
	}
	
	return 0;
}
