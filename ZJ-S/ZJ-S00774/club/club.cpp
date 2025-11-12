#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
	int a,b,c;
}a[N];
int T,n,dp[205][105][105][105],ans;
bool cmp(node x,node y)
{
	return x.a>y.a;
}
void aw1()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=min(i,n/2);j++)
		{
			for(int k=0;k<=min(i,n/2);k++)
			{
				if(j+k>i)
					break;
				int l=i-j-k;
				if(l>n/2)
					continue;
				if(l<0)
					break;
				dp[i][j][k][l]=0;
				if(j-1>=0)
					dp[i][j][k][l]=max(dp[i][j][k][l],dp[i-1][j-1][k][l]+a[i].a);
				if(k-1>=0)
					dp[i][j][k][l]=max(dp[i][j][k][l],dp[i-1][j][k-1][l]+a[i].b);
				if(l-1>=0)
					dp[i][j][k][l]=max(dp[i][j][k][l],dp[i-1][j][k][l-1]+a[i].c);
			}
		}
	}
	for(int j=0;j<=n/2;j++)
	{
		for(int k=0;k<=n/2;k++)
		{
			int l=n-j-k;
			if(l>n/2)
				continue;
			if(l<0)
				break;
			ans=max(ans,dp[n][j][k][l]);
		}
	}
}
void aw2()
{
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n/2;i++)
	{
		ans+=a[i].a;
	}
}
bool check()
{
	for(int i=1;i<=n;i++)
	{
		if(a[i].b!=0||a[i].c!=0)
			return 0;
	}
	return 1;
}
void dfs(int k,int cnt1,int cnt2,int cnt3,int sum)
{
	if(cnt1>n/2||cnt2>n/2||cnt3>n/2)
		return;
	if(k==n+1)
	{
		ans=max(ans,sum);
		return;
	}
	dfs(k+1,cnt1+1,cnt2,cnt3,sum+a[k].a);
	dfs(k+1,cnt1,cnt2+1,cnt3,sum+a[k].b);
	dfs(k+1,cnt1,cnt2,cnt3+1,sum+a[k].c);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
		}
		if(check())
		{
			aw2();
		}
		else
		{
			if(n<=15)
			{
				dfs(1,0,0,0,0);
			}
			else
			{
				aw1();				
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}