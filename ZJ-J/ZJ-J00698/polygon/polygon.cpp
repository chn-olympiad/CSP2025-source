#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
const int N=5005;
int n,ans,a[N],f[N][N];
void dfs(int x,int sum,int ma,int m)
{
	if(x==n)
	{
		if(m>=3&&ma*2<sum)
		{
			ans++;
			ans%=mod;
		}
		return;
	}
	dfs(x+1,sum+a[x+1],max(ma,a[x+1]),m+1);
	dfs(x+1,sum,ma,m);
}
bool check()
{
	for(int i=1;i<=n;i++)
		if(a[i]!=1)
			return 0;
	return 1;
}
signed main()
{
 	freopen("polygon.in","r",stdin);
 	freopen("polygon.out","w",stdout);
 	ios::sync_with_stdio(0);
 	cin.tie(0);
 	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(check())
	{
		for(int i=0;i<=n;i++)
			f[i][0]=1;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=(f[i-1][j-1]+f[i-1][j])%mod;
		for(int i=3;i<=n;i++)
		{
			ans+=f[n][i];
			ans%=mod;
		}
		cout<<ans;
	}
	else
	{
		dfs(0,0,0,0);
		cout<<ans;
	}
 	return 0;
}
