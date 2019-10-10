#include<iostream>
#include<queue>
using namespace std;
int main(){
	queue<int>inique;//inisialisasi que dengan nama variabel integer inique
	int t,a,b;
	cout<<"Masukkan bilangan ganjil; ke n yang diinginkan : ";
	cin>>t;
	for(int i=1;i<=t*2;i++){//looping i dimulai dr 1 agar ganjil dan t*2 agar luas
	
	inique.push(i);//untuk push que dengan nilai q
	i=i+1;}//untuk dapatkan nilai ganjil
	cout<<inique.back();//print que yang paling belakang


}
