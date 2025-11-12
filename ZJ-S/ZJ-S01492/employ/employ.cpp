#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
int c[1001],a[10001],vis[1001];
int n,m;
string s;
long long ans=0;
void dfs(int f,int dep)
{
	if(f>n-m)
	{
		return;
	}
	if(dep==n+1&&n-f>=m)
	{
		ans++;
		ans%=Mod;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		if(c[i]<=f||a[dep]==0)
		{
			vis[i]=1;
			dfs(f+1,dep+1);
			vis[i]=0;
		}
		else
		{
			vis[i]=1;
			dfs(f,dep+1);
			vis[i]=0;
		}
	}
	return;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	bool p=1;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=0;i<n;i++)
	{
		if(s[i]=='1') a[i+1]=1;
		else a[i+1]=0,p=0;
	}
	memset(vis,0,sizeof(vis));
	if(n<=18) dfs(0,1);
	if(m==n)
	{
		if(!p) cout<<0;
		else
		{
			ans=1;
			for(int i=1;i<=n;i++)
			{
				ans*=i;
				ans=ans%Mod;
			}
			cout<<ans;
		}
		return 0;
	}
	if(p)
	{
		ans=1;
		for(int i=1;i<=n;i++)
		{
			ans*=i;
			ans=ans%Mod;
		}
		cout<<ans;
		return 0;
	}
	cout<<ans;
	return 0;
}
