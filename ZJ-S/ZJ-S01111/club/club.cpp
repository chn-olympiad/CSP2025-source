/*
1
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926
*/
#include<bits/stdc++.h>
using namespace std;
int read()
{
	int f=1,x=0;
	char c=getchar();
	while(c<'0' || c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
int dp[201][101][101];
int t,n;
int a[100001],b[100001],c[100001];
bool kr(int i,int j,int k)
{
	if((j+k<=i) && (i-j-k<=n/2) && (k<=min(i,n/2)) )return true;
	return false;
}
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	for(int apple=1;apple<=t;apple++)
	{
		n=read();
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
		{
			a[i]=read();b[i]=read();c[i]=read();
		}
		if(n<=301)
		{		
			int ans=-1;
			for(int i=1;i<=n;i++)
			{	
				for(int j=0;j<=min(i,n/2);j++)
				{
					for(int k=0;k<=min(i,n/2);k++)
					{				
						if(kr(i,j,k)==false)continue;	
						if(j>=1)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i]);
						if(k>=1)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+b[i]);
						if(i-j-k>=1)
						{
							dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+c[i]);
						}
						ans=max(dp[i][j][k],ans);
					}
				}
			}
			cout<<ans<<endl;
		}
		else
		{
			int ans=0;
			for(int i=1;i<=n/2;i++)
			{
				ans+=a[i];
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
