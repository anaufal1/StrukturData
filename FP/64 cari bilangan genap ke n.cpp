#include<iostream>
#include<queue>
using namespace std;
int main(){
	queue<int>inique;//inisialisasi que dengan nama variabel integer inique
	int t,a,b;
	cout<<"Masukkan bilangan genap ke n yang diinginkan : ";
	cin>>t;
	inique.push(t);//push t ke que
	
	cout<<"bilangan genap ke "<<t<<" adalah :"<<inique.front()*2-2;//bilangan genap dimulai dari 0
}
