#include<iostream>
#include<cstdio> 
#include<algorithm>
using namespace std;
const int N=1e5+1;
int n;
int a[N][5],b[N];
long long ans=0,dp[101][51][51][51];
long long dfs(int x,int t1,int t2,int t3)
{
	if(x==n+1) return 0;
	if(dp[x][t1][t2][t3]!=-1) return dp[x][t1][t2][t3];
	long long tem=0;
	if(t1<n/2)
	{
		long long xx=dfs(x+1,t1+1,t2,t3)+a[x][1];
		if(xx>tem) tem=xx;
	}
	if(t2<n/2)
	{
		long long xx=dfs(x+1,t1,t2+1,t3)+a[x][2];
		if(xx>tem) tem=xx;
	}
	if(t3<n/2)
	{
		long long xx=dfs(x+1,t1,t2,t3+1)+a[x][3];
		if(xx>tem) tem=xx;
	}
	dp[x][t1][t2][t3]=tem;
	ans=max(tem,ans);
	return tem;
}
bool cmp(int x,int y)
{
	return x>y;
}
void solve()
{
	for(int i=1;i<=n;i++)
	  b[i]=a[i][1];
	sort(b+1,b+1+n,cmp);
	for(int i=1;i<=n/2;i++)
	  ans+=b[i];
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int k=1;k<=T;k++)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		  for(int j=0;j<=n/2;j++)
		    for(int x=0;x<=n/2;x++)
		      for(int y=0;y<=n/2;y++)
		          dp[i][j][x][y]=-1;
		ans=0;
		int u=0;
		for(int i=1;i<=n;i++)
	  	  for(int j=1;j<=3;j++)
	    	scanf("%d",&a[i][j]);
	    for(int i=1;i<=n;i++)
	  	  if(a[i][2]!=0||a[i][3]!=0) u=0;
	  	if(u==1) solve();
		else dfs(1,0,0,0);
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
