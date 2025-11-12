#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505;
const int mod=998244353;
int c[N],s[N],n,m,ans,used[N],b[N],f[N][N],x;
bool check()
{
	for(int i=1;i<=n;i++)
		if(!s[i])
			return 0;
	return 1;
}
void js()
{
	int res=0;
	for(int i=1;i<=n;i++)
	{
		if(res>=c[b[i]]||!s[i])
			res++;
	}
	if(n-res>=m)
		ans++,ans%=mod;
	return;
}
void dfs(int x)
{
	if(x==n+1)
	{
		js();
		return;
	}
	for(int i=1;i<=n;i++)
		if(!used[i])
		{
			used[i]=1;
			b[x]=i;
			dfs(x+1);
			b[x]=0;
			used[i]=0;
		}
}
signed main()
{
 	freopen("employ.in","r",stdin);
 	freopen("employ.out","w",stdout);
 	ios::sync_with_stdio(0);
 	cin.tie(0);
 	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		char ch;
		cin>>ch;
		s[i]=ch-'0';
	}
	for(int i=1;i<=n;i++)
		cin>>c[i];
	if(check())
	{
		for(int i=1;i<=n;i++)
			if(!c[i])
				x++;
		for(int i=0;i<=500;i++)
			f[i][0]=1;
		for(int i=1;i<=500;i++)
		for(int j=1;j<=500;j++)
			f[i][j]=f[i-1][j-1]+f[i-1][j];
		for(int i=n-x;i>=m;i--)
		{
			ans+=f[x][n-x-i]*f[n-x][i];
			ans%=mod;
		}
		cout<<ans;
	}
	else
	{
		dfs(1);
		cout<<ans;
	}
 	return 0;
}
