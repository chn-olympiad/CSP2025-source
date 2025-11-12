//club
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define endl '\n'
using namespace std;
typedef long long ll;
int const N=1e5+10;
ll dp[610][310][310];
struct node
{
	ll x,y,z;
}a[N];
ll n,ans;
bool cmp1(node x,node y)
{
	return x.x>y.x;
}
void dfs1(int x,int cnt1,int cnt2,ll sum)
{
	if(cnt1>n/2||cnt2>n/2) return;
	if(x>n)
	{
		ans=max(ans,sum);
		return;
	}
	dfs1(x+1,cnt1+1,cnt2,sum+a[x].x);
	dfs1(x+1,cnt1,cnt2+1,sum+a[x].y);
}
void dfs(int x,int cnt1,int cnt2,int cnt3,ll sum)
{
	if(cnt1>n/2||cnt2>n/2||cnt3>n/2) return;
	if(x>n)
	{
		ans=max(ans,sum);
		return;
	}	
	dfs(x+1,cnt1+1,cnt2,cnt3,sum+a[x].x);
	dfs(x+1,cnt1,cnt2+1,cnt3,sum+a[x].y);
	dfs(x+1,cnt1,cnt2,cnt3+1,sum+a[x].z);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(a,0,sizeof a);
		memset(dp,0,sizeof dp); 
		ans=0;
		scanf("%lld",&n);
		bool f2=1,f3=1;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
			if(a[i].y) f2=0;
			if(a[i].z) f3=0;
		}
		//special A
		if(f2&&f3)
		{
			sort(a+1,a+1+n,cmp1);
			for(int i=1;i<=n/2;i++)
				ans+=a[i].x;
			printf("%lld\n",ans);
			continue;
		}
		//special B
		if(f3)
		{
			dfs1(1,0,0,0);
			printf("%lld\n",ans);
			continue;
		}
		//
		if(n<=20)
		{
			dfs(1,0,0,0,0);
			printf("%lld\n",ans);
			continue;
		}
		//n<=200
		for(int i=1;i<=n;i++)
		{
			for(int y=1;y<=n/2;y++)
				dp[i][0][y]=max(dp[i-1][0][y-1]+a[i].y,dp[i-1][0][y]+a[i].z);
			for(int x=1;x<=n/2;x++)
				dp[i][x][0]=max(dp[i-1][x-1][0]+a[i].x,dp[i-1][x][0]+a[i].z);
		}
		for(int i=1;i<=n;i++)
			for(int x=1;x<=n/2;x++)
				for(int y=1;y<=n/2;y++)
					dp[i][x][y]=max(max(dp[i-1][x-1][y]+a[i].x,dp[i-1][x][y-1]+a[i].y),dp[i-1][x][y]+a[i].z);
		for(int x=0;x<=n/2;x++)
		{
			for(int y=0;y<=n/2;y++)
			{
				if(x+y>=n/2) 
					ans=max(ans,dp[n][x][y]);
			}
		}
		printf("%lld\n",ans);	
	} 
	return 0;
}

