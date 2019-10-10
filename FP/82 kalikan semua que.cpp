#include<iostream>
#include<queue>
using namespace std;
int main(){
	queue<int>inique;
	int t,a;
	long long b=1;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>a;
		inique.push(a);
	}for(int i=0;i<t;i++){
		b=b*inique.front();

	inique.pop();}	cout<<b<<" ";
}
