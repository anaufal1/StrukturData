#include<iostream>
using namespace std;

typedef struct{
    int atas;
    int bawah;
}tipe;

void printz(tipe n){
    cout<<"Hasil : "<<n.atas<<"/"<<n.bawah<<endl;
}

int main(){
    tipe z;
    cout<<"Angka atas : "; cin>>z.atas;
    cout<<"Angka bawah : "; cin>>z.bawah;
    cout<<endl;

    printz(z);
}
