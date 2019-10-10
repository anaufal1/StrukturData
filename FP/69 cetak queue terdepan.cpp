#include<iostream>
#include<queue>
using namespace std;
int main(){
	queue<int>inique;
	int t,a,b;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>a;
		inique.push(a);
	}
	cout<<inique.front();
}
