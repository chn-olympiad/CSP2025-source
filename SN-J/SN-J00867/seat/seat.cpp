#include <bits/stdc++.h>
using namespace std;
//priority_queue<int,vector<int>,less<int> >q;
long long a[1000],n,m,t=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	for(int i=2;i<=n*m;i++){
		if(a[i]>a[1]){
			t++;
		}
	}
	long long op=t/(2*n),po=t%(2*n);
	if(po==0){
		cout<<op*2<<" 1";
		return 0;
	}
	else{
		if(po>n){
			po-=n;
			cout<<op*2+2<<" "<<n-(po-1);
			return 0; 
		}else{
			cout<<op*2+1<<" "<<po;
			return 0; 
		}
	}
	return 0;
}
