#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main(){
priority_queue<int,vector<int >,greater<int> >inipque;
	int a,b,t;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>b;
		inipque.push(b);
	}
	for(int i=0;i<t;i++){
		cout<<inipque.top()<<" ";
		inipque.pop();
	}
}
