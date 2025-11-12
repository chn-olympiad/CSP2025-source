#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n;
int a[5005];
long long ans=0;
void dfs(int now,int maxx,int he){
	if(now>n){
		if(he>maxx*2)ans++;
		return;
	}
	dfs(now+1,max(maxx,a[now]),he+a[now]);
	dfs(now+1,max(maxx,0),he);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<ans%mod;
}
/*
5
2 2 3 8 10

*/
