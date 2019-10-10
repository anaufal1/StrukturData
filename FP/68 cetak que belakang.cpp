#include<stdio.h>
#include<queue>
#include<iostream>
using namespace std;
int main(){
	queue<int>inique;
	int t,a,b;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		scanf("%d",&a);
		inique.push(a);
	}
	printf("%d",inique.back());
}
