#include<bits/stdc++.h>
using namespace std;
const int MAX=1e5+10,MAXN=1e8;
long long n,a[MAX][4],ans=0;
long long dp[MAX][4][4]={0};//dp[i][j][k]=第i个人去j的分，此时去k的人
void init()
{
	scanf("%lld\n",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld %lld %lld\n",&a[i][1],&a[i][2],&a[i][3]);
	}
	ans=0;
}
void work1()
{
//	for(int i=1;i<=n;i++)
//	{
//		printf("%lld %lld %lld\n",a[i][1],a[i][2],a[i][3]);
//		printf("%lld %lld %lld\n",dp[i][1][0],dp[i][2][0],dp[i][3][0]);
//	}
		
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			for(int k=1;k<=3;k++)
			{
				if(dp[i-1][k][0]+a[i][j]>dp[i][j][0])
				{
					dp[i][j][0]=dp[i-1][k][0]+a[i][j];
					dp[i][j][1]=dp[i-1][k][1];
					dp[i][j][2]=dp[i-1][k][2];
					dp[i][j][3]=dp[i-1][k][3];
					dp[i][j][j]=dp[i-1][k][j]+1;
				}
				if(dp[i][j][j]>(n/2))	dp[i][j][0]=-MAXN;
			}
		}
		for(int j=1;j<=3;j++)
			printf("(%d,%d) %lld %lld %lld dp=%lld\n",i,j,dp[i][j][1],dp[i][j][2],dp[i][j][3],dp[i][j][0]);
	}
}
void work(int i,int j,long long cnt,int a1,int a2,int a3)
{
//	printf("(%d,%d) %d %d %d dp=%lld\n",i,j,a1,a2,a3,cnt);
	if(i==n)
	{
		ans=max(ans,cnt+a[i][j]);
		return;
	}
	if(a1+1<=(n/2))
		work(i+1,1,cnt+a[i][j],a1+1,a2,a3);
	if(a2+1<=(n/2))
		work(i+1,2,cnt+a[i][j],a1,a2+1,a3);
	if(a3+1<=(n/2))
		work(i+1,3,cnt+a[i][j],a1,a2,a3+1);
}
void output()
{
	printf("%lld\n",ans);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d\n",&t);
	while(t--)
	{
		init();
		work(0,1,0,0,0,0);
		output();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
