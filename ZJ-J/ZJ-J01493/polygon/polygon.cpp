#include<bits/stdc++.h>
using namespace std;
int n,m,a[5010],b[5010];
struct pp
{
	int ge,sm;
}dp[5010][5010];
long long ans;
void dfs(int x,int mx,long long sum,int g,int pan)
{
	
	if(g>=3&&sum>2*mx&&pan==1)
	{
		long long sums=pow(2,n-x+1);
		ans+=sums;
		ans%=998244353;
		return;
	}
	if(x>n)
	{
		return;
	}
	int mmx=mx;
	mmx=max(mmx,a[x]);
	dfs(x+1,mmx,sum+a[x],g+1,1);
	dfs(x+1,mx,sum,g,0);
}
int cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int i,j,pan=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			pan=1;
		}
	}
	if(pan==0&&n>20)
	{
		for(i=3;i<=n;i++)
		{
			long long x=1;
			for(j=0;j<i;j++)
			{
				x*=(n-j);
			}
			ans+=x;
			ans%=998244353;
		}
		cout<<ans;
		return 0;
	}
	//cout<<a[1];
	if(n<=30)
	{
		sort(a+1,a+1+n,cmp);
		dfs(1,0,0,0,0);
		cout<<ans;
		return 0;
	}
	else
	{
		sort(a+1,a+1+n);
		dp[1][1].sm=a[1];
		dp[2][1].sm=a[2];
		dp[2][2].sm=a[2]+a[1];
		for(i=1;i<=n;i++)
		{
			b[i]=b[i-1]+a[i];
		}
		for(i=1;i<=n;i++)
		{
			for(j=3;j<=n;j++)
			{
				dp[i][j].ge=dp[i-1][j].ge;
				dp[i][j].sm=dp[i-1][j].sm;
				if(a[i]<dp[i-1][j-1].sm)
				{
					int x=dp[i][j].ge,cha=b[i-1]-a[i],jia=0;
					dp[i][j].ge=max(dp[i][j].ge,dp[i-1][j-1].ge+1);
					if(x!=dp[i][j].ge)
					{
						dp[i][j].sm=dp[i-1][j-1].sm+a[i];
					}
				}
			}
		}
		for(i=3;i<=n;i++)
		{
			ans+=dp[n][i].ge;
			ans%=998244353;
		}
		cout<<ans;
		return 0;
	}
}