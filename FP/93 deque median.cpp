#include<iostream>
#include<queue>
using namespace std;
int main(){
	priority_queue<float,vector<float >,greater<float> >inideque;
	int a,b,t,c;
	float d;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>a;
		inideque.push(a);
	}
	if(t%2==0)b=t/2;
	else b=t/2;
	for(int  i=0;i<b;i++){
		c=inideque.top();
	inideque.pop();
	}
if(t%2==0){
d=inideque.top()+c;
d=d/2;

	cout<<d;}
	else cout<<inideque.top();
}
