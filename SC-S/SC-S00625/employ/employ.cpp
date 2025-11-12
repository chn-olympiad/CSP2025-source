#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,ans,ss[505],a[505],maxx=1,vis[505],jl;
string s;

void dfs(int k,int deep){
	if(deep==k+1){
		ans++;
		ans%=mod;
		return;
	}
	for(int i=1;i<=n;++i){
		if(!vis[i]&&ss[i]){
			vis[i]=1;
			dfs(k,deep+1);
			vis[i]=0;
		}
	}
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;++i){
		ss[i]=s[i-1]-'0';
		maxx=min(ss[i],maxx);
	}
	for(int i=1;i<=n;++i){
		scanf(" %lld",&a[i]);
	}
	if(maxx==1){
		for(int i=m;i<=n;++i){
			int cnt=1;
			for(int j=n,k=1;j>max(i,n-i);--j,++k){
				cnt=(cnt*j/k)%mod;
			}
			ans=(ans+cnt)%mod;
		}
		cout<<ans;
	}else{
		for(int i=m;i<=n;++i){
			dfs(i,1);
		}
		cout<<ans;
	}
	return 0;
}