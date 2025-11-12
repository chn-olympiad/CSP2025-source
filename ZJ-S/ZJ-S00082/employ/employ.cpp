#include <bits/stdc++.h>
using namespace std;
int n,m;
bool vis[505];
int c[505];
bool s[505];
long long ans=0;
void dfs(int k,int cnt)
{
	if(k==n+1) 
	{
		if(cnt>=m) ans=(ans+1)%998244353;
		return; 
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			if(c[i]>(k-cnt-1) && s[k]==1) dfs(k+1,cnt+1);
			else dfs(k+1,cnt);
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%1d",&s[i]);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	dfs(1,0);
	cout<<ans;
}