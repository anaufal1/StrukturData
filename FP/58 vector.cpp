#include<iostream>
#include<vector>
using namespace std;

int main(){
    cout<<"Push dalam VECTOR"<<endl<<endl;;

    vector<int> z;
    cout<<"Masukkan jumlah yang ingin di inputkan : ";
    int loop; cin>>loop;
    while(loop--){
        cout<<"Masukkan angka : ";
        int num; cin>>num;
        z.push_back(num);
    }
    cout<<"Isi vector adalah : ";
    for(int i=0;i<z.size();i++){
        cout<<z[i]<<" ";
    }
}
