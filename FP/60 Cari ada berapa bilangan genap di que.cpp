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
		if(inique.front()%2==0){//menyaring yang genap untuk di print
			brp=brp+1;
	}inique.pop();}
	cout<<"="<<brp;
	
}
