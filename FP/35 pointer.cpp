#include<iostream>
using namespace std;

int main(){
    int N;
    void test(int *);
    cout<<"N = "; cin>>N;
    cout<<"Angka N = "<<N<<endl;
    cout<<"Fungsi test = "; test(&N);
}

void test(int *x){
    *x=*x+6;
    cout<<*x<<endl;
}
