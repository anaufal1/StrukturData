#include<iostream>
#include<deque>
using namespace std;
int main(){
	deque<int>inideque;
	int a,t;
	char b;
	cin>>t;
	
	for(int i=0;i<t;i++){
	
		cout<<"Pilih Push Depan atau Belakang\n"<<"d untuk depan,b untuk belakang"<<endl;
		cout<<"Pilihan anda : ";
			cin>>b;
		
		if(b=='d'){
			cout<<"Masukkan angka yang ingin di push : ";
			cin>>a;
		inideque.push_front(a);}
		else if(b=='b'){
				cout<<"Masukkan angka yang ingin di push : ";
			cin>>a;
		inideque.push_back(a);
		}
	}
	cout<<"ingin pop berapa kali?";
	cin>>t;
	for(int i=0;i<t;i++){
		
		cout<<"pop depan atau belakang?\na.depan\nb.belakang"<<endl;
		cin>>b;
		if(a=='a')inideque.pop_front();
		else if(a=='b')inideque.pop_back();
	}
	
	cout<<"deque paling belakang adalah "<<inideque.back()<<endl;
	cout<<"deque paling depan adalah "<<inideque.front();
}
