#include<iostream>
#include<queue>
using namespace std;
int main(){
	queue<int>inideque;
	int a,b,t,c=0;
	float d;
	cin>>t;
	for(int i=1;i<=t;i++){
		if(t%i==0){
		
		inideque.push(i);
		c=c+1;}
	}
for(int i=0;i<c;i++){
	cout<<inideque.front()<<" ";
	inideque.pop();
}
}
