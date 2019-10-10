#include<iostream>
#include<utility>
#include <stdlib.h>
using namespace std;

typedef struct Node{
	int data,height;
	Node *left,*right;
	int counter;
	int countrl;
	int countrr;

}avl;

bool kekanan = false;

int get_height(Node *node){
	if(node->left!=NULL && node->right!=NULL){
		if(node->left->height > node->right->height){
			return node->left->height + 1;
		}
		return node->right->height +1;
	}
	else if(node->left!=NULL){
		return node->left->height+1;
	}else if(node->right!=NULL){
		return node->right->height +1;
	}

	return 1;
}

int get_balance(Node *node){

	if (node->right!=NULL && node->left!=NULL){
		return node->left->height - node->right->height;
	}else if (node->left==NULL){
		return 0-node->right->height;
	}else{
		return node->left->height;
	}

}

Node* rotateLeft(Node* node){
	Node* atas=node->right;
	node->right=atas->left;
	atas->left=node;

    node->countrr= atas->countrl;
    atas->countrl = node->countrl+node->countrr +1;

	node->height=get_height(node);
	atas->height=get_height(atas);
	return atas;
}

Node* rotateRight(Node* node){
	Node* atas=node->left;
	node->left=atas->right;
	atas->right=node;

    node->countrl = atas->countrr;
    atas->countrr = node->countrl + node->countrr +1;

	node->height=get_height(node);
	atas->height=get_height(atas);
	return atas;
}

Node* insert_tree(Node* node, int key){
	if(node == NULL){
		node=new(Node);
		node->data=key;
		node->height=1;
		node->left = node->right = NULL;
		node->counter=1;
		node->countrl= node->countrr= 0;

	return node;
	}else if(key > node->data){
        node->countrr++;
		node->right = insert_tree(node->right, key);
	}else if(key < node->data){
        node->countrl++;
		node->left = insert_tree(node->left,key);
	}else{
		node->counter +=1;
		return node;
	}


	node->height = get_height(node);
	//cout<<node->height<<endl;
	int balance_factor=get_balance(node);
//	cout<<balance_factor<<endl;

	if(balance_factor >1){
		if(key> node->left->data){//LR
			node->left=rotateLeft(node->left);
		}
		return rotateRight(node);//R
	}else if(balance_factor < -1){
		if(key < node->right->data){//RL
			node->right=rotateRight(node->right);
		}
		return rotateLeft(node);//L
	}
	return node;
}



void find(Node* node, int key,int count){
	if(node!=NULL){
		if(node->data > key){


			find(node->left,key,count);

		}else if(node->data < key){

			//count += getCount(node->left);
            count += node->countrl + 1;
			find(node->right,key,count);
		}else{

            count += node->countrl;
        //    count+= getCount(node->left);


			cout<<"sipsip!! "<<count<<endl;
			return;
		}
	}else{
	cout<<"...:((("<<endl;
	return;
	}

	return;
}


void inOrder(Node* node){
if(node!=NULL){
inOrder(node->left);
cout<<node->data<<" ";
cout<<node->height<<endl;
inOrder(node->right);
}
}

void preOrder(Node*node){
if(node!=NULL){

preOrder(node->left);
preOrder(node->right);
}
}

int main (){

	int tc;
	cin>>tc;

	avl* t=NULL;
	int key;


	while(tc--){
		int cmd;

		cin>>cmd;

		if(cmd==1){
			cin>>key;
			t = insert_tree(t,key);

		//	inOrder(t);
		//preOrder(t);
		//	cout<<endl;

		}else if (cmd==2){

            cin>>key;
			find(t, key,1);

		}


	}

	return 0;
}
