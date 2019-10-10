#include<iostream>
#include<queue>
using namespace std;
int main(){
	queue<int>inique;//membuat que dengan nama variabel integer inique
	int t;
	long long a=0,b=1,c=0;
	
	cin>>t;
	inique.push(0);
	cout<<inique.back()<<" ";
	inique.push(1);
	
for(int i=0;i<t-1;i++){//rumus untuk fibonaci
cout<<inique.back()<<" ";
		c=a+b;
	    a=b;
		b=c;
	inique.push(c);
	
}	
}

