#include<stdio.h>
#include<set>
#include<iostream>
using namespace std;
int main(){
	long long a,N,flag=1;
	int i;
	set<int>X;
	scanf("%lld",&N);
	for(i=0;i<N;i++){
		scanf("%lld",&a);
			if(X.count(a)){
				flag=0;
			}
			X.insert(a);
	}
	if(flag==0){
		printf("ada yg sama\n");
	}
	else{
		printf("tidak ada yg sama\n");
	}
	return 0;
}
