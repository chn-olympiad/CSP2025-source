#include<bits/stdc++.h>
#define int long long
using namespace std;
const int m=998244353;
int ans=0;
int a[5005];
int c[5005];
int b[5005];
int f[5005][5005];
void get24(int n)
{
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(j==0||j==i)
			{
				f[i][j]=1ll;
			}
			else
			{
				f[i][j]=(f[i-1][j-1]+f[i-1][j])%m;
			}
		}
	}
	int x=0ll;
	for(int i=3;i<=n;i++)
	{
		x=(x+f[n][i])%m;
	}
	cout<<x;
}
void dfs(int s,int h,int lst,int n)
{
	if(s==h+1)
	{
		int xx=0,yy=0;
		for(int i=1;i<=h;i++)
		{
			xx+=a[c[i]];
			yy=max(yy,a[c[i]]);
		}
		if(xx>yy*2)
		{
			ans++;
		}
		return;
	}
	for(int i=lst;i<=n;i++)
	{
		if(b[i]==0)
		{
			c[s]=i;
			b[i]=1;
			dfs(s+1,h,i+1,n);
			b[i]=0;
		}
	}
}
void get40(int n)
{
	for(int i=1;i<=n;i++)
	{
		dfs(1,i,1,n);
	}
	cout<<ans;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(a[n]==1)
	{
		get24(n);
	}
	else
	{
		get40(n);
	}
	return 0;
}
