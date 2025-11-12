#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,a[5200],jxj=0,vis[5200],mod=998244353;
int dfs(int sum,int d,int maxx,int I){
	int ans=0;
	if(d==0){
		cout<<sum<<" ";
		if(sum>maxx*2) return 1;
		else return 0;
	}
	for(int i=I;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			maxx=max(maxx,a[i]);
			ans+=dfs(sum+a[i],d-1,maxx,i)%mod;
			vis[i]=0;
		}
	}
	return ans;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		int t=dfs(0,i,0,1);
		jxj=(t+jxj)%mod;
	}
	cout<<jxj;
	return 0;
}