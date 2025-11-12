#include<bits/stdc++.h>
using namespace std;
int n,m,a,x;
priority_queue<int> que;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>x;
		if(i==1)a=x;
		que.push(x);
	}
	int tot=1;//jilu n
	int sum=1;//jilu m
	while(que.top()!=a){
		que.pop();
		tot++;
		if(tot>n){
			tot-=n;
			sum++;
		}
	}
	if(sum%2==1){
		cout<<sum<<" "<<tot;
	}
	else cout<<sum<<" "<<n-tot+1;
	return 0;
}
