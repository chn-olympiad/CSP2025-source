#include<bits/stdc++.h>
using namespace std;
const long long N=5005,mod=998244353;
int n,a[5005];
long long cnt=0;
void dfs(int x,int sum,int maxx,int ans){
	if(ans>=3&&sum>maxx*2)cnt++;
	if(x==n+1)return;
	dfs(x+1,sum,maxx,ans);
	dfs(x+1,sum+a[x],max(maxx,a[x]),ans+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0,0);
	cout<<(cnt-n+3)%mod;
	return 0;
}
