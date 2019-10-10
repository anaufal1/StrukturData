#include<iostream>
using namespace std;

struct date{
    int day;
    int month;
    int year;
};

int main(){
    struct date n;

    cout<<"Tanggal : "; cin>>n.day;
    cout<<"Bulan : "; cin>>n.month;
    cout<<"Tahun : "; cin>>n.year; cout <<endl;

    cout<<"Tanggal : "<<n.day<<"-"<<n.month<<"-"<<n.year;

}
