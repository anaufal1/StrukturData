#include<iostream> 
#include<stdlib.h> 
#include<stack> 
#include<queue> 
#include<deque> 
#include<utility>
using namespace std; 

typedef pair<int,int> payr;

int main (){
	
	int tc;
	
	cin>>tc;
	
	while(tc--){
		int n,m;
		
		cin>>n>>m;
		queue<payr> q;
		priority_queue<int> pq;
		
		if(m<n){
		for(int i=0; i<n; i++){
			int prior;
			cin>>prior;
			payr a = make_pair(prior,i);
			q.push(a);
			pq.push(prior);
		//	cout<<pq.top()<<endl;
		}
		
		int kon=0;
		
		while(1){
			payr head;
			head = q.front();
			q.pop();
		 // cout<<"head first : "<<head.first<<endl;
		
			if (head.first == pq.top()){
			//	cout<<"masuk"<<endl;
				kon++;
				pq.pop();
				if(head.second==m){
					break;
				}
			}else{
			//	cout<<"push"<<endl;
				q.push(head);
			}	
		}
		
		cout<<kon<<endl;
		
		
		}else{
			cout<<endl;
		}
		
	}

	return 0;
}

