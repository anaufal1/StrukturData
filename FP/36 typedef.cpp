#include<iostream>
using namespace std;

typedef struct{
    int tanggal;
    int bulan;
    int tahun;
}date;

int main(){
    date z;
    cout<<"Tanggal : "; cin>>z.tanggal;
    cout<<"Bulan : "; cin>>z.bulan;
    cout<<"Tahun : "; cin>>z.tahun;

    cout<<"tanggal yg diinpuy : "<<z.tanggal<<"-"<<z.bulan<<"-"<<z.tahun<<endl;
}
