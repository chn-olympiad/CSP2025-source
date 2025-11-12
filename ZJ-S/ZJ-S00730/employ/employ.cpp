#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,d[505],c[505],vis[505],flag,cnt;
long long ans;
string s;
inline void dfs(int x,int num,int sum){
	if(sum>=m){
		long long tot=1,f=0;
		for(int i=x+1;i<=n;i++)
			if(vis[i]==0)f++;
		for(int i=1;i<=f;i++)
			tot=tot*i%mod;
		ans=(ans+tot)%mod;
	}
	if(x>n)return;
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		if(d[x]==0)dfs(x+1,num+1,sum);
		else dfs(x+1,num,sum+1);
		vis[i]=0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	cin>>s;
	flag=1;
	for(int i=1;i<=n;i++){
		d[i]=s[i-1]-'0';
		if(d[i]==0)flag=0;
		if(d[i]==0)cnt++;
	}
	for(int i=1;i<=n;i++)
		cin>>c[i];
	if(flag){
		ans=1;
		for(int i=1;i<=n-cnt+1;i++)
			ans=(ans*i)%mod;
		cout<<ans<<'\n';
	}
	else{
		dfs(1,0,0);
		cout<<ans<<'\n';
	}
	return 0;
}
