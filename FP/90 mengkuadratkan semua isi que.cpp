#include<iostream>
#include<queue>
#include<math.h>
using namespace std;
int main(){
	queue<float>inique;//inisialisasi que
	int t,a,f;
	long long b=1;
	cin>>t;
	for(int i=0;i<t;i++){//looping untuk push
		cin>>a;
		inique.push(a);
	}
	cin>>f;
	for(int i=0;i<t;i++){//looping untuk print dan mengkuadratkan
		
		inique.front()=sqrt(inique.front());//rumus untuk mengkuadratkan
		cout<<inique.front()<<' ';

	inique.pop();}
}
