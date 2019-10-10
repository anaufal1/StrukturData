#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;

typedef struct Node{
	int data,height;
	Node *left,*right;
	int counter;
	char sdata[10001];
//	char sdatac[101][101];
//	int idx;
}avl;

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

	node->height=get_height(node);
	atas->height=get_height(atas);
	return atas;
}

Node* rotateRight(Node* node){
	Node* atas=node->left;
	node->left=atas->right;
	atas->right=node;

	node->height=get_height(node);
	atas->height=get_height(atas);
	return atas;
}

Node* insert_tree(Node* node, int key,char s[]){
	if(node == NULL){
		node=new(Node);
		node->data=key;
		strcpy(node->sdata,s);
		node->left = node->right = NULL;
		node->height=1;
	//	node->idx=0;
		return node;
	}else if(key > node->data){
		node->right = insert_tree(node->right, key,s);
	}else if(key < node->data){
		node->left = insert_tree(node->left,key,s);
	}else{
		
		node->data=key;
		strcat(node->sdata,"\n");
		strcat(node->sdata,s);
		
	//	strcpy(node->sdatac[node->idx],s);
	//	node->idx++;
		node->counter +=1;
		return node;
	}


	node->height = get_height(node);
	int balance_factor=get_balance(node);

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

/*void printSdataC(Node *node){
	
	for(int i=0; i<node->idx; i++){
		printf("%s\n",node->sdatac[i]);
	}
	
}*/
int power(int x, unsigned int y, int p)
{
    int res = 1;      // Initialize result
 
    x = x % p;  // Update x if it is more than or 
                // equal to p
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;  
    }
    return res;
}

int getNum(char s[]){
    int len = strlen(s);
    long int num=0;
    int i; int j;
    int tmp=0;
    for(i=0,j=len; i<len; i++,j--){
        //cout<<s[i]<<" "<<j<<endl;
     //   printf("%d\n",s[i]);
     
     //   printf("%d %d\n",t,j);
		
    //    tmp = pow(t,j);
      //  tmp%=1000;
       // printf("%d\n",tmp);
        //num += s[i];//pow(s[i],j)%1000;
       // cout<<num<<endl;
		
		num+=power(s[i],j,1000);
		
    }
   // num++;
    num%=1000;
   // cout<<num<<endl;
    return num;
}

void print(Node *t){

    if(t!=NULL){

        if(t->left != NULL && t->right != NULL){
        printf("%s\n",t->left->sdata);
       // printSdataC(t->left);
        printf("%s\n",t->right->sdata);
       // printSdataC(t->right);
		}else if(t->left != NULL){
        printf("%s\n",t->left->sdata);
		//printSdataC(t->left);
        }else if(t->right!=NULL){
        printf("%s\n",t->right->sdata);
		//printSdataC(t->right);
        }

        print(t->left);
        print(t->right);

    }
    return;
}
void inOrder(Node* node){
if(node!=NULL){
inOrder(node->left);
cout<<node->sdata<<endl;
inOrder(node->right);
}
}

void printGivenLevel(Node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%s\n", root->sdata);
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

void printLevelOrder(Node* root)
{
    int h = root->height;
    int i;
    for (i=1; i<=h; i++){
	
        printGivenLevel(root, i);
	}
}
 
/* Print nodes at a given level */


int main (){


    avl *t=NULL;
    char cmd;
    char string[101];
    int tc;

    cin>>tc;

    while(tc--){

    cin>>cmd;

    if(cmd=='i'){
        //gets(string);
        scanf("%s",&string);

        int val =getNum(string);
      //  cout<<val<<endl;
        t= insert_tree(t,val,string);
    }else if(cmd=='T'){
    	
    	if(t!=NULL){
    	printLevelOrder(t);
    	}else{
    		printf("Treea kosong\n");
		}
		/*if(t!=NULL){
        printf("%s \n",t->sdata);
		}
	   // printSdataC(t);
        print(t);*/
    }
	



    }

	return 0;
}

