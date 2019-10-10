#include<iostream>
#include<queue>
using namespace std;
int main(){
	queue<int>inideque;
	int a,b,t,c=0,e;
	float d;
	cin>>t;
	cin>>b;
	if(b>t)e=t;
	else e=b;
	for(int i=e;i<=b*t;i++){
		if(i%b==0)if(i%t==0){
		inideque.push(i);c=c+1;}
		}
	

	cout<<inideque.front()<<" ";

}
