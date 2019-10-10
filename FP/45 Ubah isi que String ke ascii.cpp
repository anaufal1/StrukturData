#include<iostream>
#include<queue>
#include<stdlib.h>
#include<string>
using namespace std;
int getVal(string data){//fungsi untuk mendapatkan nilai ascii string
	long long num = 0; int l = data.length();
	int i;
	for(i=0; i<data.length();i++){
        if(l<1)break;
        int x = (int)data[i];
        num += x;
        l--;
    }
    num %=1000;
	return num;
}
int main(){
	queue<string>inique;//inisialisasi que
	queue<int>inique2;//inisialisasi que kedua untuk menyimpan nilai int nanti
	int t,f;
	string a;
	long long b=1;
	cin>>t;
	for(int i=0;i<t;i++){//looping untuk push
		cin>>a;
		inique.push(a);
	}
	for(int i=0;i<t;i++){//looping untuk print
	inique2.push(getVal(inique.front()));//push que 2 dengan isi que 1 dijadikan int dengan fungsi getval
		
	
		cout<<inique2.back()<<' ';//print inique2 paling belakang

	inique.pop();//pop que pertama
	}
}
