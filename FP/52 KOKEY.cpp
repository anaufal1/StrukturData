#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
 
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
 
 
void pop_front(){
	if (tail==NULL){
		return;
	}
 
	if (head==tail){
		free(tail);
		tail=NULL;
		head=NULL;
		return;
	}else{
 
		node* tmp=head;
 
		head=tmp->next;
		free(tmp);
 
	}
	return;
}
int count(){
    node* tmp=head;
    int hitung=0;
 
    while(tmp!=NULL){
       tmp=tmp->next;
       hitung++;
    }
 
    return hitung;
}
 
void pushfront (int value){
	struct linklist* box = getnewnode(value);
 
	if (head==NULL){
		head=box;
		tail=box;
		return;
	}else{
 
		head->prev=box;
		box->next=head;
		head=box;
 
	}
	return;
}
 
void pushback (int value){
 
	struct linklist* box= getnewnode(value);
 
	if (head==NULL){
		head=box;
		tail=box;
		return;
	}else {
 
		box->prev=tail;
		tail->next=box;
		tail=box;
 
	}
	return;
}
 
void pushmid (int value,int indx){
	node* tmp=head;
	if (indx==0){
		pushfront(value);
		return;
	}
    int j;
	for (j=1; j<indx && tmp!=NULL; j++){
		tmp=tmp->next;
	}
 
	if(tmp==NULL){
		pushback(value);
		return;
	}else{
 
		node* box= getnewnode(value);
 
		box->prev=tmp;
		box->next=tmp->next;
		tmp->next=box;
 
		if(box->next==NULL){
			tail=box;
		}
 
	}
	return;
}
 
void insert(int value,int tanda){
    node* tmp=head;
    int k;
 
    for (k=1; k<tanda && tmp!=NULL; k++){
		tmp=tmp->next;
	}
 
    if(tanda==0){
        if(tmp==NULL){
            pushback(value);
        }else{
        tmp->val=value;
        }
        return;
    }
 
	if(tmp==NULL || tmp->next==NULL){
		pushback(value);
		return;
	}else{
 
       tmp->next->val=value;
 
	}
    return;
}
 
void pop_back(){
	if (tail==NULL){
		return;
	}
 
	if (head==tail){
		free(tail);
		tail=NULL;
		head=NULL;
		return;
	}else{
	node* tmp=head;
 
	while(tmp->next!=tail){
		tmp=tmp->next;
	}
 
	tail=tmp;
	free(tmp->next);
	tmp->next=NULL;
	}
	return;
}
 
void pop_mid(int index){
	if (tail==NULL){
		return;
	}
 
    //printf("%d\n",index);
 
	if (head==tail){
		free(tail);
		tail=NULL;
		head=NULL;
		return;
	}else{
		node* tmp=head;
		node* tmp2=NULL;
        int z;
 
        if(index==1){
            pop_front();
            return;
		}
 
		for (z=1; z<index-1; z++){
			tmp=tmp->next;
		}
 
		if (tmp->next==tail){
			pop_back();
			return;
		}
 
		if(tmp->next==NULL){
            return;
		}
 
		tmp2=tmp->next->next;
		free(tmp->next);
 
		tmp->next=tmp2;
		tmp2->prev=tmp;
        return;
 
		return;
	}
 
	return;
}
 
 
void reset(){
    node* tmp=head;
 
    if(tmp==NULL)return;
 
    while(tmp->next!=NULL){
        pop_back();
    }
        pop_front();
 
    /*while(tmp!=NULL){
        tampung=tmp;
        free(tampung);
        tmp=tmp->next;
    }*/
    return;
}
 
void print(){
	node* tmp=head;
	//printf ("Your Linked List..\n");
    //printf("%c",tmp->next);
 
	while(tmp!=NULL){
		printf ("%c",tmp->val);
		tmp=tmp->next;
	}
	//printf ("\n");
	return;
}
 
 
int main (){
 
char kal[1000100];
node* tmp=head;
 
while( gets(kal) != '\0'){
 
int i;
//if(kal[1]==' '){continue;}
 
int batas=strlen(kal);
int idx=0;
 
bool stat=false;
 
for (i=0; i<batas; i++){
    //printf ("%cx\n",kal[i]);
 
    if (kal[i]=='['){
       // printf("[\n");
        idx=0;
        //printf("%d\n",idx);
        continue;
    }else if (kal[i]==']'){
 
        idx=count();
       // printf("%d\n",idx);
 
    }else if(kal[i]=='#'){
       // printf("%d\n",idx-1);
 
       /* if(idx+1==2){
            continue;
        }else{*/
        pop_mid(idx+1);
       // printf("%d\n",idx+1);
        //}//continue;
    }else if(kal[i]=='~'){
        stat=!stat;
        //insert('kal[i]')
    }else{
        if (stat==false){
       // printf("masuk\n");
        pushmid(kal[i],idx);
       // printf("%d\n",idx);
        idx++;
        //printf("idx = %d\n",idx);
        }else{
        insert(kal[i],idx);
        idx++;
        //printf("masuk\n");
        }
    }
 
}
    //printf("akhir\n");
    print();
  if(kal[batas-1]!='\0')printf("\n");
    reset();
    //idx=0;
   // continue;
}
 
return 0;
}
