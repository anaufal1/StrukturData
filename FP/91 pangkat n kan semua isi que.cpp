#include<iostream>
#include<queue>
#include<math.h>
using namespace std;
int main(){
	queue<int>inique;//inisialisasi que
	int t,a,f;
	long long b=1;
	cin>>t;
	for(int i=0;i<t;i++){//looping untuk push
		cin>>a;
		inique.push(a);
	}
	cin>>f;
	for(int i=0;i<t;i++){//looping untuk print dan memangkatkan
		
		inique.front()=pow(inique.front(),f);//rumus untuk memangkatkan
		cout<<inique.front()<<' ';

	inique.pop();}
}
