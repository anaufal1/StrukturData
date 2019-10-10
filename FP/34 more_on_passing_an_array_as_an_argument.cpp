#include<iostream>
using namespace std;

int main(){
    void test(int val[], int max);
    int j, list[5];

    for(j=0;j<5;j++) list[j]=j;
    test(list, 5);
    for(j=0;j<5;j++) cout<<list[j]<<endl;
}

void test(int val[], int max){
    for(int j=0;j<max;j++) val[j]+=25;
}
