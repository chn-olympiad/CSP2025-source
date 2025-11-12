#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10,md=998244353;
int n,ans,a[N],b[N],f[5005][5005];
bool vis[N];
bool fl=0;
void dfs(int step)
{
	if(step>n)
	{
		int sum=0;int maxn=0;
		for(int i=1;i<=n;i++)
		{
			if(vis[i]==1)
			{
				maxn=max(a[i],maxn);
				sum+=a[i];
			}
		}
		if(sum>maxn*2)
		{
			ans++;
			ans%=md;
		}
		return;
	}
	vis[step]=1;
	dfs(step+1);
	vis[step]=0;	
	dfs(step+1);
}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)fl=1;
	}
	if(n<=25)
	{
		dfs(1);
		cout<<ans<<"\n";
		ans=0;
		return 0;
	}
	if(fl==0)
	{
		f[1][1]=1;
		f[2][1]=f[2][2]=1;
		for(int i=3;i<=5005;i++)
		{
			for(int j=1;j<=i;j++)
			{
				f[i][j]=(f[i-1][j]+f[i-1][j-1]+md)%md;
			}
		}
		for(int j=3;j<=n;j++)
		{
			ans=(ans%md+f[n+1][j+1])%md;
		}
		cout<<(ans+md)%md;
		return 0;
	}	
	return 0;
}
/*

5
1 2 3 4 5

5
2 2 3 8 10

10
1 1 1 1 1 1 1 1 1 1

6
1 1 1 1 1 1

20
75 28 15 26 12 8 90 42 90 43 14 26 84 83 14 35 98 38 37 1
*/