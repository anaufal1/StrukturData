#include<iostream>
#include<queue>
using namespace std;
int main(){
	queue<int>inique;
	int t,a,f;
	long long b=1;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>a;
		inique.push(a);
	}
	cin>>f;
	for(int i=0;i<t;i++){
		
		inique.front()*=f;
		cout<<inique.front()<<' ';

	inique.pop();}
}
