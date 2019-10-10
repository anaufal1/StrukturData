#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#define RogueValue -9999
#define MaxStack 10
using namespace std;

typedef struct{
	int top;
	int ST[MaxStack];
}StackType, *Stack;

int main(){
	Stack initStack();
	int empty(Stack);
	void push (Stack, int);
	int pop(Stack);
	int n;
	Stack S=initStack();
	cin>>n;
	while(n!=0){
		push(S, n);
		cin>>n;
	}
	while(!empty(S)){
		cout<<pop(S);
	}
	cout<<endl;
}

Stack initStack(){
	Stack sp=(Stack)malloc(sizeof(StackType));
	sp->top=-1;
	return sp;
}

int empty(Stack S){
	return (S->top==-1);
}

void push(Stack S, int n){
	if(S->top==MaxStack-1){
		cout<<endl<<"Stack Overflow"<<endl;
		exit(1);
	}
	++(S->top);
	S->ST[S->top]=n;
}

int pop(Stack S){
	if(empty(S)) return RogueValue;
	int hold=S->ST[S->top];
	--(S->top);
	return hold;
}
