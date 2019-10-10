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

typedef struct node_c{
	double value;
	struct node_c *down;
}node_t_c;

typedef struct{
	node_t_c *top;
}stackC;

int countIn, countPost;
int inFix[1000], postFix[1000];
double x, y;

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

void pushCal(int val, stackC* s){
	node_t_c *temp = (node_t_c*) malloc (sizeof(node_t_c));
	temp->value = val - 48;
	temp->down = s->top;
	s->top = temp;
}

void operasi(int otor, stackC *s){
	node_t_c *temp;
	temp = s->top;
	y = temp->value;
	x = temp->down->value;
	if(otor == '+'){
		temp->value = x + y;
	}
	else if(otor == '-'){
		temp->value = x - y;
	}
	else if(otor == '*'){
		temp->value = x * y;
	}
	else if(otor == '/'){
		temp->value = x / y;
	}
	s->top->down = s->top->down->down;
}

void kalkulator(stackC *s){
	while(postFix[countPost] != '\n'){
		if(isalnum(postFix[countPost])){
			pushCal(postFix[countPost], s);
			countPost++;
		}
		else{
			operasi(postFix[countPost], s);
			countPost++;
		}
			printf("%lf\n", s->top->value);
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
	stackC *c = (stackC*) malloc (sizeof(stackC));
	c->top = NULL;
	s->top = NULL;
	
	printf("-----------------------------------PROGRAM KALKULATOR------------------------------------\n");
	printf("-----------------------------------------1 DIGIT-----------------------------------------\n\n");
	
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
	
	s->top = NULL;
	resetCounter(3);
	kalkulator(c);
	
	printf("%lf", c->top->value);
	
	return 0;
}
