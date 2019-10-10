#include<iostream>
#include<queue>
using namespace std;
int main(){
	queue<int>inideque;
	int a,b,t,c=0,e;
	cout<<"Program membenarkan tahun ke tahun kabisat terakir\n";
	cout<<"Masukkan Tahun : ";
	int kabisat;
	
	cin>>t;
	for(int i=1;i<=t;i++){
		if(i%400==0)inideque.push(i);
		else if(i%4==0)if(i%100!=0){
		
		inideque.push(i);
		c=c+1;
	}
	
		}
	cout<<"Yang termasuk tahun kabisat sampi tahun ke "<<t<<" adalah : \n";
for(int i=0;i<c;i++){
	cout<<inideque.front()<<" ";
inideque.pop();
}
}
