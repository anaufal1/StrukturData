#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct node{
	int value;
	struct node *down;
}node_t;

typedef struct{
	node_t *top;
}stack;

int countIn, countPost;
int inFix[1000], postFix[1000];

int hirarkiOp(int val){
	if(val == '+' || val == '-') return 1;
	else if(val == '*' || val == '/') return 2;
}

void pop(stack *s){
	node_t *temp;
	temp = s->top;
	postFix[countPost] = temp->value;
	countPost++;
	s->top = temp->down;
	free(temp);
}

void push(int val, stack *s){
	node_t *temp = (node_t*) malloc (sizeof(node_t));
	if(!s->top){
		temp->value = val;
		temp->down = s->top;
		s->top = temp;
	}
	else{
		while(1){
			if(hirarkiOp(s->top->value) >= hirarkiOp(val)){
				pop(s);
			}
			else{
				temp->value = val;
				temp->down = s->top;
				s->top = temp;
				break;
			}
			if(!s->top){
				temp->value = val;
				temp->down = s->top;
				s->top = temp;
				return;
			}
		}
	}
}

void pemisah(stack *s){
	while(inFix[countIn] != '\n'){
		if(inFix[countIn] == '('){
			while(1){
				countIn++;
				if(inFix[countIn] == ')'){
					countIn++;
					break;
				}
			}
			if(inFix[countIn] == '\n') break;
		}
		if(isalnum(inFix[countIn])){
			postFix[countPost] = inFix[countIn];
			countPost++;
			countIn++;
		}
		else{
			push(inFix[countIn], s);
			countIn++;
		}
	}
	while(s->top){
		pop(s);
	}
	postFix[countPost] = '\n';
}

void pemisahKurung(stack *s){
	while(inFix[countIn] != ')'){
		if(isalnum(inFix[countIn])){
			postFix[countPost] = inFix[countIn];
			countPost++;
			countIn++;
		}
		else{
			push(inFix[countIn], s);
			countIn++;
		}
	}
	while(s->top){
		pop(s);
	}
}

void cekKurung(stack *s){
	while(1){
		if(inFix[countIn] == '('){
			countIn++;
			pemisahKurung(s);
		}
		if(inFix[countIn] == '\n') break;
		countIn++;
	}
}

void resetCounter(int val){
	if(val == 1) countIn = 0;
	else if(val == 2) countPost = 0;
	else if(val == 3){
		countIn = 0;
		countPost = 0;
	}
}

int main(){
	stack *s = (stack*) malloc (sizeof(stack));
	s->top = NULL;
	
	printf("----------------------------PROGRAM PENGUBAH INFIX----------------------------\n");
	printf("--------------------------------MENJADI POSTFIX-------------------------------\n\n");
	
	resetCounter(3);
	printf("Masukkan Operasi Dalam Bentuk Infix :\n");
	while(1){
		scanf("%c", &inFix[countIn]);
		if(inFix[countIn] == '\n') break;
		countIn++;
	}
	
	resetCounter(3);
	cekKurung(s);
	
	resetCounter(1);
	pemisah(s);
	
	resetCounter(2);
	printf("\nOperasi Dalam Bentuk Postfix Adalah :\n");
	while(1){
		printf("%c", postFix[countPost]);
		if(postFix[countPost] == '\n') break;
		countPost++;
	}
	
	return 0;
}
