#include<stack>
#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<stdlib.h>
#include<queue>
using namespace std;
	
	stack<int> stk;
	queue<int> qganjil;
	queue<int> qgenap;


int main (){
	
	int k;
	//cin>>k;
	scanf("%d",&k);
	int num;	
	//int tc=13;
	
	while(scanf("%d",&num)!=EOF){
		//scanf("%d",&num);
		stk.push(num);
	}	
	
	int kon=stk.size();
	for(int i=kon; i>k; i--){
		//cout<<" "<<stk.top()<<endl;
		printf(" %d\n",stk.top());
		stk.pop();
	}
	
	//cout<<endl;
	printf("\n");
	
	for(int j=0; j<k; j++){
		
		if(stk.top()%2==0){
		//	cout<<"masuk genap"<<endl;
			qgenap.push(stk.top());
		}else{
		//	cout<<"masuk ganjil"<<endl;
			qganjil.push(stk.top());
		}
		stk.pop();
	}
	
	while(!qganjil.empty() && !qgenap.empty()){
		printf("%d %d\n",qganjil.front(),qgenap.front());
		qganjil.pop();
		qgenap.pop();
	}
	
	while(!qganjil.empty()){
		printf("%d\n",qganjil.front());
		qganjil.pop();
	}

	while(!qgenap.empty()){
		printf("  %d\n",qgenap.front());
		qgenap.pop();
	}
	
	return 0;
}
