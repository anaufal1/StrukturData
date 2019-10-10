#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int> z;
    cout<<"Mencari top stack dalam STL"<<endl<<endl;
    cout<<"Masukkan test case : ";
    int loop; cin>>loop;
    while(loop--){
        cout<<"Masukkan angka : ";
        int num; cin>>num;
        z.push(num);
    }
    cout<<"Nilai stack paling atas adalah : ";
    cout<<z.top()<<endl;
}
