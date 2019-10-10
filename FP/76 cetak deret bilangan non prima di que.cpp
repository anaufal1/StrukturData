#include<iostream>
#include<queue>
using namespace std;
int main(){
	queue<int>inique;//inisialisasi que dengan nama variabel integer inique
	int t,a,b,brp=1,i=0;
	cin>>t;

	while(i<t){//looping untuk meng push que

	if(brp==2||brp==3||brp==5||brp==7){++brp;}
	else if(brp==1||brp%2==0||brp%3==0||brp%5==0||brp%7==0){inique.push(brp);
brp++;++i;;
		}
	else{
	brp++;}
	}
	for(int i=0;i<t;i++){//looping print
	cout<<inique.front()<<" ";
	inique.pop();
	
}
}
