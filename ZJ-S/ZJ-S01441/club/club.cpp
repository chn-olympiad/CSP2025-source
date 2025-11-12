#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int T,n,mx,dp[205][205][205];
struct stu
{
	int x,y,z;
}a[maxn];
bool cmp2(stu x0,stu y0)
{
	return x0.x>y0.x;
}
inline void dfs(int x,int ta,int tb,int tc,int sum)
{
	if(x>n)
	{
		mx=max(mx,sum);
		return;
	}
	if(ta<n/2)dfs(x+1,ta+1,tb,tc,sum+a[x].x);
	if(tb<n/2)dfs(x+1,ta,tb+1,tc,sum+a[x].y);
	if(tc<n/2)dfs(x+1,ta,tb,tc+1,sum+a[x].z);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		mx=0;
		bool is2=0,is3=0;
		memset(dp,0,sizeof(dp));
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].y!=0)is2=1;
			if(a[i].z!=0)is3=1;
		}
		if(!is2&&!is3)
		{
			sort(a+1,a+n+1,cmp2);
			for(int i=1;i<=n/2;i++)ans+=a[i].x;
			cout<<ans<<'\n';
			continue;
		}
		if(!is3)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=n/2;j>=0;j--)
				{
					for(int k=n/2;k>=0;k--)
					{
						if(j>0)dp[j][k][0]=max(dp[j][k][0],dp[j-1][k][0]+a[i].x);
						if(k>0)dp[j][k][0]=max(dp[j][k][0],dp[j][k-1][0]+a[i].y);
					}
				}
			}
			cout<<dp[n/2][n/2][0]<<'\n';
			continue;
		}
		for(register int i=1;i<=n;i++)
		{
			for(register int j=n/2;j>=0;j--)
			{
				for(register int k=n/2;k>=0;k--)
				{
					for(register int t=n/2;t>=0;t--)
					{
						if(j>0)dp[j][k][t]=max(dp[j][k][t],dp[j-1][k][t]+a[i].x);
						if(k>0)dp[j][k][t]=max(dp[j][k][t],dp[j][k-1][t]+a[i].y);
						if(t>0)dp[j][k][t]=max(dp[j][k][t],dp[j][k][t-1]+a[i].z);
					}
				}
				
			}
		}
		cout<<dp[n/2][n/2][n/2]<<'\n';
	}
	return 0;
}