#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out","w", stdout);
	int n, m;
	cin>>n>>m;
	int t=n*m;
	int x=0, y=0;
	int cnt=1;
	cin>>x;
	for(int i=2;i<=t;i++){
		cin>>y;
		if(y>x){
			cnt++;
		}
	}
	int p=cnt/m;
	int q=cnt%m;
	if(q==0){
		if(p%2==0){
			cout<<p<<' '<<1;
		}
		else{
			cout<<p<<' '<<m;	
		}
	}
	else{
		if(p%2==0){
			cout<<p+1<<' '<<q;
		}
		else{
			cout<<p+1<<' '<<n-q+1;
		}
	}
	
	return 0;
}
