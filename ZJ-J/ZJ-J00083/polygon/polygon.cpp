#include<bits/stdc++.h>
using namespace std;
int n,a[5010],ans,bo,mod=998244353;
long long s,f[5010];
void dfs(int k,int l,int MAX,int s){
	if(k>3&&MAX*2<s)++ans;
	if(k>n)return;
	for(int i=l+1;i<=n;++i)dfs(k+1,i,max(MAX,a[i]),s+a[i]);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]>1)bo=1;
	}
	if(!bo){
		f[0]=1;
		for(int i=1;i<=n;++i)for(int j=n;j;--j)f[j]=(f[j]+f[j-1])%mod;
		for(int i=3;i<=n;++i)s=(s+f[i])%mod;
		cout<<s<<"\n";
		return 0;
	}
	dfs(1,0,0,0);
	cout<<ans<<"\n";
	return 0;
}
