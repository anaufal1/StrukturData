#include<iostream>
#include<queue>
using namespace std;
int main(){
	queue<int>inideque;
	int a,b,t,c=0,e;
	float d;
	cin>>t;
	cin>>b;
	if(b<t)e=t;
	else e=b;
	for(int i=2;i<=e;i++){
		if(t%i==0 && b%i==0){
		
		inideque.push(i);
		c=c+1;}
	}

	cout<<inideque.back()<<" ";

}
