#include<bits/stdc++.h>
using namespace std;
int n,a[5005],m,vis[5005];
long long ans;
const int mod=998244353;
void dfs(int k,int v){
	if(k>m){
		int t=0,maxn=0;
		for(int i=1;i<=m;i++){
			t+=vis[i];
			maxn=max(maxn,vis[i]);
		}
		if(t>maxn*2){
			ans++;
		}
		return;
	}
	for(int i=v+1;i<=n-(m-k);i++){
		vis[k]=a[i];
		dfs(k+1,i);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(m=3;m<=n;m++){
		dfs(1,0);
		ans=ans%mod;
	}
	cout<<ans;
}