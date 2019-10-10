#include<iostream>
#include<stdlib.h>
#include <stdio.h>
#include <utility>
#include <vector>
using namespace std;

typedef struct Node{
int val;
Node*left;
Node*right;

}tree;

Node* insertTree(Node*node,int key){
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

void printWhatToPrint(vector<int> whatToPrint){

    for(int i=0; i<whatToPrint.size(); ++i){
        if(i==whatToPrint.size()-1){
            cout<< whatToPrint[i];
        }else{
        cout << whatToPrint[i]<<" ";
        }
    }
    cout<<endl;
}

void preOrder(Node*node,vector<int> whatToPrint){
if(node!=NULL){
//cout<<node->val<<" ";
if(node->left!=NULL || node->right!=NULL){
    whatToPrint.push_back(node->val);
}else{
    whatToPrint.push_back(node->val);
    printWhatToPrint(whatToPrint);
}

preOrder(node->left,whatToPrint);
preOrder(node->right,whatToPrint);

}
}

int height(Node* node)
{
    if (node==NULL)
        return 0;
    else
    {

        int lheight = height(node->left);
        int rheight = height(node->right);


        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}

void printGivenLevel(Node* root, int level,vector<int> whatToPrint)
{
    if (root == NULL)
        return;
    if (level == 1){
        if(root->left!=NULL || root->right!=NULL)
            preOrder(root,whatToPrint);
    }
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1,whatToPrint);
        printGivenLevel(root->right, level-1,whatToPrint);
    }
}

void printLevelOrder(Node* root,vector<int> whatToPrint)
{
    int h = height(root);
    int i;
    for (i=1; i<=h; i++)
        printGivenLevel(root, i,whatToPrint);
}

int main(){
    tree *t=NULL;
    vector<int> whatToPrint;

    int n;
    cin>>n;
     while(n--){
        int num;
        cin>>num;
        t=insertTree(t,num);
     }

    printLevelOrder(t,whatToPrint);


    return 0;
}
