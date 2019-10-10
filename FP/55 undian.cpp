#include<stdio.h>
#include<stdlib.h>
struct linklist{

	int val;
	struct linklist* next;
	struct linklist* prev;

};

typedef struct linklist node;
node* head; node* tail;

struct linklist* getnewnode(int value){

	node* box = (node*)malloc(sizeof(node));
	box->val=value;
	box->next=NULL;
	box->prev=NULL;
	return box;

}

void pushback (int value){

	struct linklist* box= getnewnode(value);

	if (head==NULL){
		head=box;
		tail=box;
	//	head->prev=box;
		head->next=box;
		tail->next=box;
	//	tail->prev=box;
		return;
	}else {

		//box->prev=tail;
		tail->next=box;
		tail=box;
		tail->next=head;
	//	head->prev=tail;
	}
	return;
}


void print(){
	node* tmp=head;
	printf ("Your Linked List..\n");
    int i=5;
	while(i>=-10){
		printf ("%d ",tmp->val);
		tmp=tmp->next;
		i--;
	}
	printf ("\n");
	return;
}

int main (){

    int n;
    int skip;

    //printf("Banyaknya kandidat? : ");
    scanf("%d",&n);
    //printf("Putaran Undian yg diinginkan? : ");
    scanf("%d",&skip);

    int i;
    for(i=1; i<=n; i++){
        pushback(i);
    }

   // print();

    node* tmp=tail;
    node* tmp2=NULL;
	int j;

	for (j=0; j<n; j++){
			tmp=tmp->next;
		for (i=0; i<skip; i++){
			 tmp2=tmp;
		}
		printf("%d ",tmp2->next->val);
		tmp2->next=tmp2->next->next;
	}


 

    return 0;
}
