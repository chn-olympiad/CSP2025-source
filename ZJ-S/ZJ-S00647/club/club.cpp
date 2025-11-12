#include<bits/stdc++.h>
using namespace std;
int inline read()
{
	int sum=0;
	char s=getchar();
	while('0'>s||s>'9')
		s=getchar();
	while('0'<=s&&s<='9')
	{
		sum=sum*10+s-'0';
		s=getchar();
	}
	return sum;
}
bool cmp(int a,int b)
{
	return a>b;
}
int a[100001],b[100001],c[100001];
long long dp[201][101][101][101];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,i,j,k,l,maxb,maxc;
	long long ans;
	t=read();
	while(t--)
	{
		ans=maxb=maxc=0;
		n=read();
		for(i=1;i<=n;i++)
		{
			a[i]=read();
			b[i]=read();
			maxb=max(maxb,b[i]);
			c[i]=read();
			maxc=max(maxc,c[i]);
		}
		if(maxb==0&&maxc==0)
		{
			sort(a+1,a+1+n,cmp);
			for(i=1;i<=n/2;i++)
				ans+=a[i];
			printf("%d\n",ans);
			continue;
		}
		if(maxc==0)
		{
			for(i=1;i<=n;i++)
				for(j=1;j<=n/2;j++)
					for(k=1;k<=n/2;k++)
					{
						dp[i][j][k][1]=max({dp[i-1][j-1][k][1]+a[i],dp[i-1][j][k-1][1]+b[i]});
						ans=max(ans,dp[i][j][k][1]);
					}
			printf("%d\n",ans);
			continue;
		}
		for(i=1;i<=n;i++)
			for(j=1;j<=n/2;j++)
				for(k=1;k<=n/2;k++)
					for(l=1;l<=n/2;l++)
					{
						dp[i][j][k][l]=max({dp[i-1][j-1][k][l]+a[i],dp[i-1][j][k-1][l]+b[i],dp[i-1][j][k][l-1]+c[i]});
						ans=max(ans,dp[i][j][k][l]);
					}
		printf("%d\n",ans);
	}
	return 0;
}
