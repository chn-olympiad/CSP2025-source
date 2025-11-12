#include<bits/stdc++.h>
using namespace std;
int n,m;
int maxx=-1,maxn=-1;
int o(int n,int m){
	if(n%m)return n/m+1;
	return n/m;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		int x;cin>>x;
		if(x>maxx){
			maxx=x;
			maxn=i;
		}
	}
	cout<<o(maxn,n)<<" ";
	if(o(maxn,n)%2){
		if(maxn%n==0)cout<<n;
		else cout<<maxn%n;
	}else cout<<maxn%n+1;
	return 0;
}
