#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
typedef struct node{
	long long val;
	int countr,countl,index;
	node* left;
	node* right;
}Node;

Node* insertTree(Node *node,long long key,int countidx/*mulai dari 1*/){
	if(node==NULL){
		node=new Node;
		node->val=key;
		node->left=node->right=NULL;
		node->index=countidx;
		cout<<countidx<<endl;
	} else if( key < node->val ){
		node->index+=1;
		node->left=insertTree(node->left,key,countidx);
	}else{
	 	countidx+=node->index;
		node->right=insertTree(node->right,key,countidx);
	}
	return node;
}

int cariDataDariIndex(Node *node,int idx){

	if(node!=NULL){
		if(node->index == idx){
		//	cout<<node->index<<endl;
			return node->val;
		}else if(node->index > idx){
			cariDataDariIndex(node->left,idx);
		}else{
			cariDataDariIndex(node->right,idx);
		}
	}else{
		return 0;
	}
}

void Median(Node* node,int size){
	double tengah;
	if(size%2==0){
		tengah=(cariDataDariIndex(node,(size-1)/2)+cariDataDariIndex(node,((size-1)/2)+1));
	//	printf("%.1f\n",tengah);
	}else{
		tengah=cariDataDariIndex(node,size/2);
	//	printf("%.1f\n",tengah);
	}


}


void search(Node* node, int count,long long key,int *flag){
	if(node!=NULL){
		if(node->val == key){
		count = count + node->countr+1;
		*flag = count;
		cout<<count<<endl;
		return;
		}
		else if(key > node->val){

		search(node->right,count,key,flag);
		}
		else{
		count = count+node->countr+1;
		search(node->left,count,key,flag);
		}


	}
}


int main(){
	Node* tre=NULL;

	int num;
	int n=0;
	while(scanf("%d",&num)!=EOF){
		int count=0;
		tre= insertTree(tre,num,count);
		n++;
		Median(tre, n);
	}

	return 0;
}
