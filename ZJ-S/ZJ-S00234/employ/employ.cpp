#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],sb,cg,ans,l,y,jd[505],mod=998244353;
bool vis[505];
char c[505];
inline void dfs(int k)
{
	if(sb>n-m) return;
	if(k==n+1)
	{
		if(cg>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			vis[i]=1;
			jd[k]=a[i];
			if(jd[k]<=sb||c[k]=='0') sb++;
			else cg++;
			dfs(k+1);
			vis[i]=0;
			if(jd[k]<=sb||c[k]=='0') sb--;
			else cg--;
		}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	bool f=0;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]!='1') f=0;
	}
	if(f==1)
	{
		int sum=0;
		for(int i=1;i<=n;i++) cin>>a[i],sum+=a[i]!=0;
		if(sum<m) cout<<0;
		else if(sum==n)
		{
			ans=1;
			for(int i=1;i<=n;i++) ans*=i,ans%=mod;
			cout<<ans;
		}
		else
		{
			ans=1;
			for(int i=1;i<=n;i++) ans*=i,ans%=mod;
			cout<<ans;
		}
		exit(0);
	}
	int sum=0;
	for(int i=1;i<=n;i++) cin>>a[i],sum+=a[i]!=0;
	if(sum<m) cout<<0;
	dfs(1);
	cout<<ans;
	return 0;
}
