#include<stdio.h>
#include<iostream>
#include<stack>
using namespace std;
int main(){
	stack<int>inistack;
	int a,b,t;
	cout<<"Masukkan banyak angka yang ingin di push : ";
cin>>t;

cout<<"masukkan angka yang ingin di push : ";
	for(int i=0;i<t;i++){
		cin>>b;
		inistack.push(b);
	}
	cout<<"isi dari stack anda adalah : \n";
	for(int i=0;i<t;i++){
	
	cout<<inistack.top()<<endl;
	inistack.pop();}
}
