#include<iostream>
#include<queue>
using namespace std;
int main(){
	queue<int>inique;//inisialisasi que dengan nama variabel integer inique
	int t,a,b,brp=0;
	cin>>t;
	for(int i=0;i<t;i++){//looping untuk meng push que
		cin>>a;
		inique.push(a);
	}for(int i=0;i<t;i++){//looping print
		if(inique.front()==2||inique.front()==3||inique.front()==5||inique.front()==7){inique.pop();}
	else if(inique.front()==1||inique.front()%2==0||inique.front()%3==0||inique.front()%5==0||inique.front()%7==0){
	
		cout<<inique.front()<<' ';inique.pop();}
	else{
	inique.pop();}
}
}
