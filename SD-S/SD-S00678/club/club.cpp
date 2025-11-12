#include<bits/stdc++.h>
using namespace std;
int T,n,a[100005][4],ans,kl,e[10],dp[100005][5];
int g[100005];
void dfs(int x,int s,int h,int w,int u)
{
	if(x==n+1)
	{
		ans=max(ans,s);
		return ;
	}
	if(h<n/2)
		dfs(x+1,s+a[x][1],h+1,w,u);
	if(w<n/2)
		dfs(x+1,s+a[x][2],h,w+1,u);
	if(u<n/2)
		dfs(x+1,s+a[x][3],h,w,u+1);
	return ;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		scanf("%d",&n);
		ans=0;
		kl=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				scanf("%d",&a[i][j]);
				if(!a[i][j])
					e[j]++;
			}
		}
		if(e[2]==n&&e[3]==n)
		{
			for(int i=1;i<=n;i++)
				g[i]=a[i][1];
			sort(g+1,g+1+n);
			long long d=0;
			for(int i=n;i>=n/2;i--)
				d+=g[i];
			cout<<d;
			continue;
		}	
		if(n<=30)
			dfs(1,0,0,0,0);
		else
		{
			for(int i=1;i<=n/2;i++)
			{
				int r=0;
				for(int j=1;j<=3;j++)
				{
					r=max(dp[i-1][j],r);
				}
				for(int j=1;j<=3;j++)
					dp[i][j]=r+a[i][j];
			}
			for(int i=n/2+1;i<=n;i++)
			{		
				dp[i][1]=max(dp[i-1][2],dp[i-1][3]);
				dp[i][1]+=a[i][1];
				dp[i][2]=max(dp[i-1][1],dp[i-1][3]);
				dp[i][2]+=a[i][2];
				dp[i][3]=max(dp[i-1][1],dp[i-1][2]);
				dp[i][3]+=a[i][3];
				ans=max(ans,dp[i][1]);
				ans=max(ans,dp[i][2]);
				ans=max(ans,dp[i][3]);
			}	
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
