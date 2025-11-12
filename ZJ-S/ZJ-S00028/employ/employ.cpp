#include<bits/stdc++.h>
#define int long long 
using namespace std;
int a[551],t[551],b[551];
int vis[551];
string s;
int n,m,tot=0;
int ans=0;
int mod=998244353;
void dfs(int x,int hv)
{
	if(hv==m)
	{
		int res=1;
		for(int i=n-x+1;i>=1;i--)
		{
			res=res*i%mod;
		}
		ans=ans+res;
		ans%=mod;
		return;
	}
	if(x>n&&hv<m)return;
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==1)continue;
		vis[i]=1;
		int op=0;
		if(s[x-1]=='1'&&x-hv-1<b[i])op=1;
		dfs(x+1,hv+op);
		vis[i]=0;
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int i,j,k;
	cin>>n>>m;
	cin>>s;
	for(i=1;i<=n;i++)
	{
		if(s[i-1]=='1')a[++tot]=i;
	}
	for(i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		b[i]=x;
		t[x]++;
	}
	for(i=1;i<=n;i++)
	{
		t[i]+=t[i-1];
	}
	if(tot==n)
	{
		if(t[n]-t[0]<m) cout<<0;
		else
		{
			int res=1;
			for(i=n,j=t[n]-t[0];i>=1&&j>=1;i--,j--)
			{
				res=res*i%mod;
			}
			cout<<res;
		}
	} 
	else
	{
		dfs(1,0);
		cout<<ans;
	}
	return 0;	
} 
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3

17：47 发现思路错误，爆炸了，写暴力 
17:51 性质A就是全排 
*/
