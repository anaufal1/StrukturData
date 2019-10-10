#include<iostream>
#include<deque>
using namespace std;
int main(){
	deque<float>inideque;
	int a,b,t;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>a;
		inideque.push_front(a);
	}
	for(int i=0;i<t-1;i++){
		inideque.front()=inideque.front()+inideque.back();
		inideque.pop_back();
	}
	cout<<inideque.front()/t;
}
