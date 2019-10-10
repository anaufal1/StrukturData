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

int main(){
	stack *s = (stack*) malloc (sizeof(stack));
	stack *b = (stack*) malloc (sizeof(stack));
	s->top = NULL;
	b->top = NULL;
	
	long long i, n, q, max;
	long long val;
	
	max = 0;
	
	for(i = 0; ; i++){
		scanf("%lld", &q);
		if(q == 1){
			scanf("%lld", &val);
			push(val, s);
			if(i == 0){
				push(val, b);
			}
			else{
				if(s->top->value >= b->top->value){
					push(val, b);
				}
			}
		}
		else if(q == 2){
			if(s->top->value == b->top->value){
				pop(s);
				pop(b);
			}
			else{
				pop(s);
			}
		}
		else if(q == 3){
			if(!b->top){
				printf("-1\n");
			}
			else{
				printf("%lld\n", b->top->value);
			}
		}
		else if (q == -1){
			return 0;
		}
	}	
	return 0;
}
