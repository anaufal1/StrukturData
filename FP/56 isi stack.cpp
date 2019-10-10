#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int> z;
    cout<<"Mencari jumlah isi stack dalam STL"<<endl<<endl;
    z.push(2);
    z.push(3);
    z.push(4);
    z.push(5);
    z.push(6);
    z.push(7);
    z.push(8);
    z.push(9);
    cout<<"Nilai stack paling atas adalah : ";
    cout<<z.size()<<endl;
}
