#include<iostream>
#include<queue>
#include<math.h>
using namespace std;
int main(){
	queue<int>inique;//inisialisasi que
	int t,f;
	char a;
	long long b=1;
	cin>>t;
	for(int i=0;i<t;i++){//looping untuk push
		cin>>a;
		inique.push(a);//push untuk char
	}
	for(int i=0;i<t;i++){//looping untuk print 
		
	
		cout<<inique.front()<<' ';

	inique.pop();}
}
