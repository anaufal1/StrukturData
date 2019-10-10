#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <string.h>
using namespace std;

int main(){

    int banyakPaket;
    cin >> banyakPaket;

    long long int paket[banyakPaket];

    for(int i=0; i<banyakPaket; i++){
        long long int jumlah;
        cin>>jumlah;
        paket[i]=jumlah;
    }

    char command[10];
    int query;
    long long int boxMax;
    long long int box=0;
    int idx=0;

    cin>>query>>boxMax;

    stack<long long int> paketInbox;


    for(int j=0; j<query; j++){
        cin>>command;
        if(strcmp(command,"tambah")==0){
            box+= paket[idx];
            paketInbox.push(paket[idx]);
            idx++;
        }else{
            if(!paketInbox.empty()){
            box-= paketInbox.top();
            paketInbox.pop();
            }
        }

    }

    if(box==boxMax){
        cout<<boxMax<<" "<<paketInbox.size()<<endl;
    }else{
        cout<<"-1"<<endl;
    }


 return 0;
}
