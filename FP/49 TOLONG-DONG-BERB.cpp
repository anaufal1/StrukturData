#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <utility>
using namespace std;
typedef pair<int,int> per;

typedef struct Node{
per val;
Node*left;
Node*right;
}tree;


Node *insertTree(Node*node,per key){
 if(node==NULL){
 node= new(Node);
   node->val=key;
    node->left = node->right = NULL;
 	 } else if(key<node->val){
	 node->left=insertTree(node->left,key);
	 } else{
	  node->right=insertTree(node->right,key);
	  }
	  return node;
}

int cariDiTree(Node *node,int total,per a,per b){


	while(node!=NULL){

	if(node->val.second != a.second && node->val.second != b.second){
		//cout<<node->val<<endl;
	//	cout<<"masuk"<<endl;
		if(total > node->val.first){
			node=node->right;

		}else if(total < node->val.first){
			node=node->left;
		}else{
			return 1;
		}


	}else{


	if(total > node->val.first){
		//cout<<"right"<<endl;
		node=node->right;
	}else if(total < node->val.first){
		node=node->left;
		//cout<<"left"<<endl;
	}else{
        return 0;
	}

	}


	}
	return 0;
}

void getResult(Node *node,long long int sum,int n,per a[]){

		int i,j;
		long long int total=sum;

		for(i=0; i<n; i++){
		//	cout<<"for1"<<endl;
			for(j=0; j<n; j++){
				//cout<<"for2"<<endl;
				if(i!=j){
				//	cout<<"i!=j"<<endl;
					total-= a[i].first;
					total-= a[j].first;
					cout<<"total : "<<total<<endl;
				//	deleteTree(node,a[i]);
				//	deleteTree(node,a[j]);
				//	cout<<"deleteTree"<<endl;
					printf("cari return : %d\n",cariDiTree(node,total,a[i],a[j]));

					if(cariDiTree(node,total,a[i],a[j])==1){
						//ketemu
						cout<<"IYAP"<<endl;
						return;
					}else{
						//next
				//		cout<<"gagal"<<endl;
						total=sum;
				//		insertTree(node,a[i]);
				//		insertTree(node,a[j]);
					}

				}
			}
		}

		cout<<"NOPE"<<endl;
		return;
}



int main (){
	int tc;
	tree *t=NULL;
	cin>>tc;

	per a[1400];

	while(tc--){

		int n;
		cin>>n;
		for(int i=0; i<n; i++){
			int val;
			cin>>val;

            per b=make_pair(val,i);
			t= insertTree(t,b);


            per a[i]=b;

		}

		long long int sum;
		cin>>sum;
		getResult(t,sum,n,a);
		t=NULL;

	}


	return 0;
}
