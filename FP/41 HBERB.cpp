#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;


typedef struct node{
  int value;
  struct node* next;
}Node;

typedef struct st{
 Node* head; // Posisi teratas dari Stack
 int size; // Banyak elemen di Stack
}stack;


void push(stack* st, int value){
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->value = value;
	temp->next = NULL;

	if(!st->head){ // Kasus apabila Stack kosong
	st->head = temp;
	}else{ // Kasus Stack sudah terisi

	temp->next = st->head;
	st->head = temp;

	}

	st->size++; // Jangan lupa increment size
	return;
}

int pop(stack *st){
	if(st->size <= 0) // Contoh handling Stack kosong
	return -1;

Node* temp = st->head;

int value = temp->value;
st->head = temp->next;

st->size--;
free(temp);

return value;

}

int main (){
	int a,b,c;

	scanf("%d%d%d",&a,&b,&c);

	stack st1={NULL,0};
	stack st2={NULL,0};
	stack st3={NULL,0};

	int val;
	while(a--){
		//cin>>val;
		push(&st1,val);
	}

	while(b--){
		//cin>>val;
		push(&st2,val);
	}

	while(c--){
		//cin>>val;
		push(&st3,val);
	}

	if(b<=a && b<=c){

		int sum1=pop(&st1);
		int sum2=pop(&st2);
		int sum3=pop(&st3);
		int max;
		int flag=1;
		//compare sampe abis sizenya

		while(st2.size){

			//klo jumlahnya sama
			if(sum2 == sum3  && sum2==sum1){
				max=sum2;
				sum2+=pop(&st2);
			}else{

				flag=1;

				if(sum3!=sum2 && sum3<sum2){
				sum3+=pop(&st3);
				flag=0;
				}

				if(sum1!=sum2 && sum1<sum2){
				sum1+=pop(&st1);
				flag=0;
				}

				if(flag){
					sum2+=pop(&st2);
				}

			}

		}

		cout<<max;



	}




	return 0;
}
