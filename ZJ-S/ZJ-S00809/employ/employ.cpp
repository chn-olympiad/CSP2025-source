#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,ans,c[505],s[505],a[505];
bool vis[505],t=1;
void work(int a[])
{
	int res=0,fail=0;
	for(int i=1;i<=n;i++)
	{
		if(c[a[i]]<=fail)
		{
			fail++;
			continue;
		}
		if(s[i]==1)
			res++;
		else
			fail++;
	}
	if(res>=m)
		(ans+=1)%=mod;
}
void dfs(int x,int a[])
{
	if(x==n+1)
	{
		work(a);
		return;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			a[x]=i;
			vis[i]=true;
			dfs(x+1,a);
			vis[i]=false;
		}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		char cc;
		cin>>cc;
		s[i]=cc-'0';
		if(s[i]!=0)
			t=0;
	}
	for(int i=1;i<=n;i++)
		cin>>c[i];
	dfs(1,a);
	cout<<ans;
}